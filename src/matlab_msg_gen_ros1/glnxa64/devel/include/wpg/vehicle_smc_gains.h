// Generated by gencpp from file wpg/vehicle_smc_gains.msg
// DO NOT EDIT!


#ifndef WPG_MESSAGE_VEHICLE_SMC_GAINS_H
#define WPG_MESSAGE_VEHICLE_SMC_GAINS_H


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
struct vehicle_smc_gains_
{
  typedef vehicle_smc_gains_<ContainerAllocator> Type;

  vehicle_smc_gains_()
    : header()
    , timestamp(0)
    , timestamp_sample(0)
    , k_gains()
    , beta_gains()
    , lambda_gains()  {
      k_gains.assign(0.0);

      beta_gains.assign(0.0);

      lambda_gains.assign(0.0);
  }
  vehicle_smc_gains_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , timestamp(0)
    , timestamp_sample(0)
    , k_gains()
    , beta_gains()
    , lambda_gains()  {
  (void)_alloc;
      k_gains.assign(0.0);

      beta_gains.assign(0.0);

      lambda_gains.assign(0.0);
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint64_t _timestamp_type;
  _timestamp_type timestamp;

   typedef uint64_t _timestamp_sample_type;
  _timestamp_sample_type timestamp_sample;

   typedef boost::array<float, 3>  _k_gains_type;
  _k_gains_type k_gains;

   typedef boost::array<float, 3>  _beta_gains_type;
  _beta_gains_type beta_gains;

   typedef boost::array<float, 3>  _lambda_gains_type;
  _lambda_gains_type lambda_gains;





  typedef boost::shared_ptr< ::wpg::vehicle_smc_gains_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::wpg::vehicle_smc_gains_<ContainerAllocator> const> ConstPtr;

}; // struct vehicle_smc_gains_

typedef ::wpg::vehicle_smc_gains_<std::allocator<void> > vehicle_smc_gains;

typedef boost::shared_ptr< ::wpg::vehicle_smc_gains > vehicle_smc_gainsPtr;
typedef boost::shared_ptr< ::wpg::vehicle_smc_gains const> vehicle_smc_gainsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::wpg::vehicle_smc_gains_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::wpg::vehicle_smc_gains_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::wpg::vehicle_smc_gains_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::wpg::vehicle_smc_gains_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::wpg::vehicle_smc_gains_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::wpg::vehicle_smc_gains_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::wpg::vehicle_smc_gains_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::wpg::vehicle_smc_gains_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::wpg::vehicle_smc_gains_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b73fdccb333beb67d87e5eba68379cc3";
  }

  static const char* value(const ::wpg::vehicle_smc_gains_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb73fdccb333beb67ULL;
  static const uint64_t static_value2 = 0xd87e5eba68379cc3ULL;
};

template<class ContainerAllocator>
struct DataType< ::wpg::vehicle_smc_gains_<ContainerAllocator> >
{
  static const char* value()
  {
    return "wpg/vehicle_smc_gains";
  }

  static const char* value(const ::wpg::vehicle_smc_gains_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::wpg::vehicle_smc_gains_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n"
"\n"
"uint64 timestamp\n"
"uint64 timestamp_sample\n"
"\n"
"float32[3] k_gains\n"
"float32[3] beta_gains\n"
"float32[3] lambda_gains\n"
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

  static const char* value(const ::wpg::vehicle_smc_gains_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::wpg::vehicle_smc_gains_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.timestamp);
      stream.next(m.timestamp_sample);
      stream.next(m.k_gains);
      stream.next(m.beta_gains);
      stream.next(m.lambda_gains);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct vehicle_smc_gains_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::wpg::vehicle_smc_gains_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::wpg::vehicle_smc_gains_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "timestamp: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.timestamp);
    s << indent << "timestamp_sample: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.timestamp_sample);
    s << indent << "k_gains[]" << std::endl;
    for (size_t i = 0; i < v.k_gains.size(); ++i)
    {
      s << indent << "  k_gains[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.k_gains[i]);
    }
    s << indent << "beta_gains[]" << std::endl;
    for (size_t i = 0; i < v.beta_gains.size(); ++i)
    {
      s << indent << "  beta_gains[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.beta_gains[i]);
    }
    s << indent << "lambda_gains[]" << std::endl;
    for (size_t i = 0; i < v.lambda_gains.size(); ++i)
    {
      s << indent << "  lambda_gains[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.lambda_gains[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // WPG_MESSAGE_VEHICLE_SMC_GAINS_H