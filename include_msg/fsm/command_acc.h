// Generated by gencpp from file fsm/command_acc.msg
// DO NOT EDIT!


#ifndef FSM_MESSAGE_COMMAND_ACC_H
#define FSM_MESSAGE_COMMAND_ACC_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace fsm
{
template <class ContainerAllocator>
struct command_acc_
{
  typedef command_acc_<ContainerAllocator> Type;

  command_acc_()
    : header()
    , comid(0)
    , command(0)
    , sub_mode(0)
    , ready(0)
    , cmdd(0)
    , pos_sp()
    , vel_sp()
    , acc_sp()
    , yaw_sp(0.0)
    , yaw_rate_sp(0.0)  {
      pos_sp.assign(0.0);

      vel_sp.assign(0.0);

      acc_sp.assign(0.0);
  }
  command_acc_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , comid(0)
    , command(0)
    , sub_mode(0)
    , ready(0)
    , cmdd(0)
    , pos_sp()
    , vel_sp()
    , acc_sp()
    , yaw_sp(0.0)
    , yaw_rate_sp(0.0)  {
  (void)_alloc;
      pos_sp.assign(0.0);

      vel_sp.assign(0.0);

      acc_sp.assign(0.0);
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint32_t _comid_type;
  _comid_type comid;

   typedef uint8_t _command_type;
  _command_type command;

   typedef uint8_t _sub_mode_type;
  _sub_mode_type sub_mode;

   typedef uint8_t _ready_type;
  _ready_type ready;

   typedef uint8_t _cmdd_type;
  _cmdd_type cmdd;

   typedef boost::array<float, 3>  _pos_sp_type;
  _pos_sp_type pos_sp;

   typedef boost::array<float, 3>  _vel_sp_type;
  _vel_sp_type vel_sp;

   typedef boost::array<float, 3>  _acc_sp_type;
  _acc_sp_type acc_sp;

   typedef float _yaw_sp_type;
  _yaw_sp_type yaw_sp;

   typedef float _yaw_rate_sp_type;
  _yaw_rate_sp_type yaw_rate_sp;





  typedef boost::shared_ptr< ::fsm::command_acc_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::fsm::command_acc_<ContainerAllocator> const> ConstPtr;

}; // struct command_acc_

typedef ::fsm::command_acc_<std::allocator<void> > command_acc;

typedef boost::shared_ptr< ::fsm::command_acc > command_accPtr;
typedef boost::shared_ptr< ::fsm::command_acc const> command_accConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::fsm::command_acc_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::fsm::command_acc_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::fsm::command_acc_<ContainerAllocator1> & lhs, const ::fsm::command_acc_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.comid == rhs.comid &&
    lhs.command == rhs.command &&
    lhs.sub_mode == rhs.sub_mode &&
    lhs.ready == rhs.ready &&
    lhs.cmdd == rhs.cmdd &&
    lhs.pos_sp == rhs.pos_sp &&
    lhs.vel_sp == rhs.vel_sp &&
    lhs.acc_sp == rhs.acc_sp &&
    lhs.yaw_sp == rhs.yaw_sp &&
    lhs.yaw_rate_sp == rhs.yaw_rate_sp;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::fsm::command_acc_<ContainerAllocator1> & lhs, const ::fsm::command_acc_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace fsm

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::fsm::command_acc_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::fsm::command_acc_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fsm::command_acc_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::fsm::command_acc_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fsm::command_acc_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::fsm::command_acc_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::fsm::command_acc_<ContainerAllocator> >
{
  static const char* value()
  {
    return "31e2116d0a2fc1d6c4f7df261378aa15";
  }

  static const char* value(const ::fsm::command_acc_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x31e2116d0a2fc1d6ULL;
  static const uint64_t static_value2 = 0xc4f7df261378aa15ULL;
};

template<class ContainerAllocator>
struct DataType< ::fsm::command_acc_<ContainerAllocator> >
{
  static const char* value()
  {
    return "fsm/command_acc";
  }

  static const char* value(const ::fsm::command_acc_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::fsm::command_acc_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"std_msgs/Header header\n"
"\n"
"#enum Command\n"
"#{\n"
"#    Move_ENU,\n"
"#    Move_Body,\n"
"#    Hold,\n"
"#    Land,\n"
"#    Disarm,\n"
"#    Failsafe_land,\n"
"#    Custom\n"
"#};\n"
"\n"
"# sub_mode 2-bit value:\n"
"# 0 for position, 1 for vel, 1st for xy, 2nd for z.\n"
"#                   xy position     xy velocity\n"
"# z position       	0b00(0)       0b10(2)\n"
"# z velocity		0b01(1)       0b11(3)\n"
"#\n"
"\n"
"uint32 comid\n"
"uint8 command\n"
"uint8 sub_mode\n"
"uint8 ready\n"
"uint8 cmdd\n"
"float32[3] pos_sp      ## [m]\n"
"float32[3] vel_sp      ## [m/s]\n"
"float32[3] acc_sp\n"
"float32 yaw_sp          ## [du]\n"
"float32 yaw_rate_sp\n"
"\n"
"\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::fsm::command_acc_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::fsm::command_acc_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.comid);
      stream.next(m.command);
      stream.next(m.sub_mode);
      stream.next(m.ready);
      stream.next(m.cmdd);
      stream.next(m.pos_sp);
      stream.next(m.vel_sp);
      stream.next(m.acc_sp);
      stream.next(m.yaw_sp);
      stream.next(m.yaw_rate_sp);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct command_acc_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::fsm::command_acc_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::fsm::command_acc_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "comid: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.comid);
    s << indent << "command: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.command);
    s << indent << "sub_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.sub_mode);
    s << indent << "ready: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.ready);
    s << indent << "cmdd: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cmdd);
    s << indent << "pos_sp[]" << std::endl;
    for (size_t i = 0; i < v.pos_sp.size(); ++i)
    {
      s << indent << "  pos_sp[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.pos_sp[i]);
    }
    s << indent << "vel_sp[]" << std::endl;
    for (size_t i = 0; i < v.vel_sp.size(); ++i)
    {
      s << indent << "  vel_sp[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.vel_sp[i]);
    }
    s << indent << "acc_sp[]" << std::endl;
    for (size_t i = 0; i < v.acc_sp.size(); ++i)
    {
      s << indent << "  acc_sp[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.acc_sp[i]);
    }
    s << indent << "yaw_sp: ";
    Printer<float>::stream(s, indent + "  ", v.yaw_sp);
    s << indent << "yaw_rate_sp: ";
    Printer<float>::stream(s, indent + "  ", v.yaw_rate_sp);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FSM_MESSAGE_COMMAND_ACC_H
