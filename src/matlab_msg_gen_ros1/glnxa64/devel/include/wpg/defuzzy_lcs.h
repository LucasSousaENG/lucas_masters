// Generated by gencpp from file wpg/defuzzy_lcs.msg
// DO NOT EDIT!


#ifndef WPG_MESSAGE_DEFUZZY_LCS_H
#define WPG_MESSAGE_DEFUZZY_LCS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace wpg
{
template <class ContainerAllocator>
struct defuzzy_lcs_
{
  typedef defuzzy_lcs_<ContainerAllocator> Type;

  defuzzy_lcs_()
    : header()
    , New_P(0.0)
    , New_I(0.0)
    , New_D(0.0)  {
    }
  defuzzy_lcs_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , New_P(0.0)
    , New_I(0.0)
    , New_D(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _New_P_type;
  _New_P_type New_P;

   typedef double _New_I_type;
  _New_I_type New_I;

   typedef double _New_D_type;
  _New_D_type New_D;





  typedef boost::shared_ptr< ::wpg::defuzzy_lcs_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::wpg::defuzzy_lcs_<ContainerAllocator> const> ConstPtr;

}; // struct defuzzy_lcs_

typedef ::wpg::defuzzy_lcs_<std::allocator<void> > defuzzy_lcs;

typedef boost::shared_ptr< ::wpg::defuzzy_lcs > defuzzy_lcsPtr;
typedef boost::shared_ptr< ::wpg::defuzzy_lcs const> defuzzy_lcsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::wpg::defuzzy_lcs_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::wpg::defuzzy_lcs_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace wpg

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'wpg': ['/home/lucas/catkin_ws/src/matlab_msg_gen_ros1/glnxa64/src/wpg/msg'], 'std_msgs': ['/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg', '/home/lucas/Matlab/sys/ros1/glnxa64/ros1/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::wpg::defuzzy_lcs_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::wpg::defuzzy_lcs_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::wpg::defuzzy_lcs_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::wpg::defuzzy_lcs_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::wpg::defuzzy_lcs_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::wpg::defuzzy_lcs_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::wpg::defuzzy_lcs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5018cc07f3c892cd87cba9a4e4753da2";
  }

  static const char* value(const ::wpg::defuzzy_lcs_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5018cc07f3c892cdULL;
  static const uint64_t static_value2 = 0x87cba9a4e4753da2ULL;
};

template<class ContainerAllocator>
struct DataType< ::wpg::defuzzy_lcs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "wpg/defuzzy_lcs";
  }

  static const char* value(const ::wpg::defuzzy_lcs_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::wpg::defuzzy_lcs_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"float64 New_P\n"
"float64 New_I\n"
"float64 New_D\n"
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

  static const char* value(const ::wpg::defuzzy_lcs_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::wpg::defuzzy_lcs_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.New_P);
      stream.next(m.New_I);
      stream.next(m.New_D);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct defuzzy_lcs_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::wpg::defuzzy_lcs_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::wpg::defuzzy_lcs_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "New_P: ";
    Printer<double>::stream(s, indent + "  ", v.New_P);
    s << indent << "New_I: ";
    Printer<double>::stream(s, indent + "  ", v.New_I);
    s << indent << "New_D: ";
    Printer<double>::stream(s, indent + "  ", v.New_D);
  }
};

} // namespace message_operations
} // namespace ros

#endif // WPG_MESSAGE_DEFUZZY_LCS_H