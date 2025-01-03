// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for wpg/fuzzy_vel_modif
#include "boost/date_time.hpp"
#include "boost/shared_array.hpp"
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#pragma warning(disable : 4127)
#pragma warning(disable : 4267)
#pragma warning(disable : 4068)
#pragma warning(disable : 4245)
#else
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"
#endif //_MSC_VER
#include "ros/ros.h"
#include "wpg/fuzzy_vel_modif.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class WPG_EXPORT wpg_msg_fuzzy_vel_modif_common : public MATLABROSMsgInterface<wpg::fuzzy_vel_modif> {
  public:
    virtual ~wpg_msg_fuzzy_vel_modif_common(){}
    virtual void copy_from_struct(wpg::fuzzy_vel_modif* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const wpg::fuzzy_vel_modif* msg, MultiLibLoader loader, size_t size = 1);
};
  void wpg_msg_fuzzy_vel_modif_common::copy_from_struct(wpg::fuzzy_vel_modif* msg, const matlab::data::Struct& arr,
               MultiLibLoader loader) {
    try {
        //header
        const matlab::data::StructArray header_arr = arr["Header"];
        auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
        msgClassPtr_header->copy_from_struct(&msg->header,header_arr[0],loader);
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Header' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Header' is wrong type; expected a struct.");
    }
    try {
        //distance_to_obstacle
        const matlab::data::TypedArray<double> distance_to_obstacle_arr = arr["DistanceToObstacle"];
        msg->distance_to_obstacle = distance_to_obstacle_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DistanceToObstacle' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DistanceToObstacle' is wrong type; expected a double.");
    }
    try {
        //distance_to_objective
        const matlab::data::TypedArray<double> distance_to_objective_arr = arr["DistanceToObjective"];
        msg->distance_to_objective = distance_to_objective_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DistanceToObjective' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DistanceToObjective' is wrong type; expected a double.");
    }
    try {
        //velocity
        const matlab::data::TypedArray<double> velocity_arr = arr["Velocity"];
        msg->velocity = velocity_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Velocity' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Velocity' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T wpg_msg_fuzzy_vel_modif_common::get_arr(MDFactory_T& factory, const wpg::fuzzy_vel_modif* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","DistanceToObstacle","DistanceToObjective","Velocity"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("wpg/fuzzy_vel_modif");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // distance_to_obstacle
    auto currentElement_distance_to_obstacle = (msg + ctr)->distance_to_obstacle;
    outArray[ctr]["DistanceToObstacle"] = factory.createScalar(currentElement_distance_to_obstacle);
    // distance_to_objective
    auto currentElement_distance_to_objective = (msg + ctr)->distance_to_objective;
    outArray[ctr]["DistanceToObjective"] = factory.createScalar(currentElement_distance_to_objective);
    // velocity
    auto currentElement_velocity = (msg + ctr)->velocity;
    outArray[ctr]["Velocity"] = factory.createScalar(currentElement_velocity);
    }
    return std::move(outArray);
  } 
class WPG_EXPORT wpg_fuzzy_vel_modif_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~wpg_fuzzy_vel_modif_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          wpg_fuzzy_vel_modif_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<wpg::fuzzy_vel_modif,wpg_msg_fuzzy_vel_modif_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         wpg_fuzzy_vel_modif_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<wpg::fuzzy_vel_modif,wpg::fuzzy_vel_modif::ConstPtr,wpg_msg_fuzzy_vel_modif_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         wpg_fuzzy_vel_modif_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<wpg::fuzzy_vel_modif,wpg_msg_fuzzy_vel_modif_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(wpg_msg_fuzzy_vel_modif_common, MATLABROSMsgInterface<wpg::fuzzy_vel_modif>)
CLASS_LOADER_REGISTER_CLASS(wpg_fuzzy_vel_modif_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1