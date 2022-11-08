#include "dynamic_env_generator/dynamic_env_generator.h"

/*************************************************
 * 创建动态障碍物点云
 *  输入：
 *      障碍物尺寸；
 *      障碍物中心位置；
 *      分辨率；
 *      类型：长方体1，圆柱体2；
 *  输出：
 *      障碍物点云；
 *************************************************/
pcl::PointCloud<pcl::PointXYZ> DynamicEnvGenerator::generate_dynamic_obs(std::vector<double> obs_size, std::vector<double> obs_pos, double resolution, int type)
{
    pcl::PointCloud<pcl::PointXYZ> obs_cloud;

    /* 长方体类型障碍物 */
    if (type == 1)
    {
        /* 侧面点云 */
        for (double z = (obs_pos[2] - obs_size[2]/2.0); z <= (obs_pos[2] + obs_size[2]/2.0); z = z + resolution)
        {
            for (double x = (obs_pos[0] - obs_size[0]/2.0); x <= (obs_pos[0] + obs_size[0]/2.0); x = x + resolution)
            {
                double const_y; // 固定y值
                pcl::PointXYZ pt_temp;
                const_y = obs_pos[1] - obs_size[1]/2.0;
                pt_temp.x = x;
                pt_temp.y = const_y;
                pt_temp.z = z;
                obs_cloud.points.push_back(pt_temp);
                const_y = obs_pos[1] + obs_size[1]/2.0;
                pt_temp.x = x;
                pt_temp.y = const_y;
                pt_temp.z = z;
                obs_cloud.points.push_back(pt_temp);
            }
            
            for (double y = (obs_pos[1] - obs_size[1]/2.0); y <= (obs_pos[1] + obs_size[1]/2.0); y = y + resolution)
            {
                double const_x; // 固定x值
                pcl::PointXYZ pt_temp;
                const_x = obs_pos[0] - obs_size[0]/2.0;
                pt_temp.x = const_x;
                pt_temp.y = y;
                pt_temp.z = z;
                obs_cloud.points.push_back(pt_temp);
                const_x = obs_pos[0] + obs_size[0]/2.0;
                pt_temp.x = const_x;
                pt_temp.y = y;
                pt_temp.z = z;
                obs_cloud.points.push_back(pt_temp);
            }
        }

        /* 顶面点云 */
        for (double x = (obs_pos[0] - obs_size[0]/2.0); x <= (obs_pos[0] + obs_size[0]/2.0); x = x + resolution)
        {
            for (double y = (obs_pos[1] - obs_size[1]/2.0); y <= (obs_pos[1] + obs_size[1]/2.0); y = y + resolution)
            {
                double const_z; // 固定y值
                pcl::PointXYZ pt_temp;
                const_z = obs_pos[2] + obs_size[2]/2.0;
                pt_temp.x = x;
                pt_temp.y = y;
                pt_temp.z = const_z;
                obs_cloud.points.push_back(pt_temp);
            }
        }
    }

    return obs_cloud;
}

void DynamicEnvGenerator::msg_pub_timerCallback(const ros::TimerEvent & /*event*/)
{
    /* add dynamic obs cloud */
    dynamic_cloud.points.clear();
    for (int i = 0; i < dynamic_obs_num; i++)
    {
        std::vector<double> pos_temp;
        pos_temp.push_back(obs_poses[3*i]);
        pos_temp.push_back(obs_poses[3*i+1]);
        pos_temp.push_back(obs_poses[3*i+2]);
        std::vector<double> size_temp;
        size_temp.push_back(obs_sizes[3*i]);
        size_temp.push_back(obs_sizes[3*i+1]);
        size_temp.push_back(obs_sizes[3*i+2]);
        pcl::PointCloud<pcl::PointXYZ> cloud_temp = generate_dynamic_obs(size_temp, pos_temp, voxel_resolution, 1);
        for (int j = 0; j < cloud_temp.points.size(); j++)
        {
            dynamic_cloud.points.push_back(cloud_temp.points[j]);
        }

        /* update obs poses */
        obs_poses[3*i] = obs_poses[3*i] + obs_velocities[3*i] * 0.10;
        obs_poses[3*i+1] = obs_poses[3*i+1] + obs_velocities[3*i+1] * 0.10;
        obs_poses[3*i+2] = obs_poses[3*i+2] + obs_velocities[3*i+2] * 0.10;
        float dist2 = pow(obs_poses[3*i] - origin_poses[3*i], 2) + pow(obs_poses[3*i+1] - origin_poses[3*i+1], 2) + pow(obs_poses[3*i+2] - origin_poses[3*i+2], 2);
        if (dist2 >= moving_ranges[i]*moving_ranges[i]) // change velocities
        {
            obs_velocities[3*i] = -obs_velocities[3*i];
            obs_velocities[3*i+1] = -obs_velocities[3*i+1];
            obs_velocities[3*i+2] = -obs_velocities[3*i+2];
        }
    }

    /* convert to ROS msg */
    sensor_msgs::PointCloud2 cloud_msg;
    pcl::toROSMsg(dynamic_cloud, cloud_msg);
    dynamic_env_cloud_puber.publish(cloud_msg);    
}

void DynamicEnvGenerator::static_cloud_subCallback(const sensor_msgs::PointCloud2ConstPtr& msg)
{
    // dynamic_cloud.points.clear();

    pcl::PointCloud<pcl::PointXYZ> static_cloud;
    pcl::fromROSMsg(*msg, static_cloud);
    for (int i = 0; i < static_cloud.points.size(); i++)
    {
        dynamic_cloud.points.push_back(static_cloud.points[i]);
    }
}

/* generate dynamic environment */
void DynamicEnvGenerator::generate_dynamic_env(ros::NodeHandle& n)
{
    nh = n;

    /* init parameters */
    nh.param<int>("/dynamic_env_generator/dynamic_obs_num", dynamic_obs_num, 0);
    nh.param<double>("/dynamic_env_generator/voxel_resolution", voxel_resolution, 0.1);
    nh.getParam("/obs_poses", obs_poses);
    origin_poses = obs_poses;
    nh.getParam("/obs_sizes", obs_sizes);
    nh.getParam("/obs_velocities", obs_velocities);
    nh.getParam("/moving_ranges", moving_ranges);
    dynamic_cloud.header.frame_id = "world";

    /* check params */
    std::cout << "dynamic obs num:" << dynamic_obs_num << std::endl;
    std::cout << "params size:" << obs_poses.size() << "," << obs_velocities.size() << "," << obs_sizes.size() << std::endl;
    if (dynamic_obs_num > obs_poses.size()/3 || dynamic_obs_num > obs_velocities.size()/3 || dynamic_obs_num > obs_sizes.size()/3)
    {
        std::cout << "[ERROR]: Numbers of obstacles doesn't match numbers of params!" << std::endl;
    }
    
    /* init subers, timers and pubers */
    static_cloud_suber = nh.subscribe<sensor_msgs::PointCloud2>("/mock_map", 1, &DynamicEnvGenerator::static_cloud_subCallback, this);
    dynamic_env_cloud_puber = nh.advertise<sensor_msgs::PointCloud2>("/sim_env_cloud", 1);
    msg_pub_timer = nh.createTimer(ros::Duration(0.10), &DynamicEnvGenerator::msg_pub_timerCallback, this);
}
