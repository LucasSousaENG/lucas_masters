// Generated by gencpp from file wpg/fuzzy.msg
// DO NOT EDIT!


#ifndef WPG_MESSAGE_FUZZY_H
#define WPG_MESSAGE_FUZZY_H


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
struct fuzzy_
{
  typedef fuzzy_<ContainerAllocator> Type;

  fuzzy_()
    : header()
    , Error(0.0)
    , D_Error(0.0)
    , P_val(0.0)
    , I_val(0.0)
    , D_val(0.0)  {
    }
  fuzzy_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , Error(0.0)
    , D_Error(0.0)
    , P_val(0.0)
    , I_val(0.0)
    , D_val(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _Error_type;
  _Error_type Error;

   typedef double _D_Error_type;
  _D_Error_type D_Error;

   typedef double _P_val_type;
  _P_val_type P_val;

   typedef double _I_val_type;
  _I_val_type I_val;

   typedef double _D_val_type;
  _D_val_type D_val;





  typedef boost::shared_ptr< ::wpg::fuzzy_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::wpg::fuzzy_<ContainerAllocator> const> ConstPtr;

}; // struct fuzzy_

typedef ::wpg::fuzzy_<std::allocator<void> > fuzzy;

typedef boost::shared_ptr< ::wpg::fuzzy > fuzzyPtr;
typedef boost::shared_ptr< ::wpg::fuzzy const> fuzzyConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::wpg::fuzzy_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::wpg::fuzzy_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::wpg::fuzzy_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::wpg::fuzzy_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::wpg::fuzzy_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::wpg::fuzzy_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::wpg::fuzzy_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::wpg::fuzzy_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::wpg::fuzzy_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a369fa74dd9c10ab03af42e68eb33e4c";
  }

  static const char* value(const ::wpg::fuzzy_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa369fa74dd9c10abULL;
  static const uint64_t static_value2 = 0x03af42e68eb33e4cULL;
};

template<class ContainerAllocator>
struct DataType< ::wpg::fuzzy_<ContainerAllocator> >
{
  static const char* value()
  {
    return "wpg/fuzzy";
  }

  static const char* value(const ::wpg::fuzzy_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::wpg::fuzzy_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"float64 Error \n"
"float64 D_Error \n"
"float64 P_val \n"
"float64 I_val \n"
"float64 D_val \n"
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

  static const char* value(const ::wpg::fuzzy_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::wpg::fuzzy_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.Error);
      stream.next(m.D_Error);
      stream.next(m.P_val);
      stream.next(m.I_val);
      stream.next(m.D_val);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct fuzzy_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::wpg::fuzzy_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::wpg::fuzzy_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "Error: ";
    Printer<double>::stream(s, indent + "  ", v.Error);
    s << indent << "D_Error: ";
    Printer<double>::stream(s, indent + "  ", v.D_Error);
    s << indent << "P_val: ";
    Printer<double>::stream(s, indent + "  ", v.P_val);
    s << indent << "I_val: ";
    Printer<double>::stream(s, indent + "  ", v.I_val);
    s << indent << "D_val: ";
    Printer<double>::stream(s, indent + "  ", v.D_val);
  }
};

} // namespace message_operations
} // namespace ros

#endif // WPG_MESSAGE_FUZZY_H