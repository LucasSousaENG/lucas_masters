// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for wpg/fuzzy_lcs
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
#include "wpg/fuzzy_lcs.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class WPG_EXPORT wpg_msg_fuzzy_lcs_common : public MATLABROSMsgInterface<wpg::fuzzy_lcs> {
  public:
    virtual ~wpg_msg_fuzzy_lcs_common(){}
    virtual void copy_from_struct(wpg::fuzzy_lcs* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const wpg::fuzzy_lcs* msg, MultiLibLoader loader, size_t size = 1);
};
  void wpg_msg_fuzzy_lcs_common::copy_from_struct(wpg::fuzzy_lcs* msg, const matlab::data::Struct& arr,
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
        //kP
        const matlab::data::TypedArray<double> kP_arr = arr["KP"];
        msg->kP = kP_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'KP' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'KP' is wrong type; expected a double.");
    }
    try {
        //kI
        const matlab::data::TypedArray<double> kI_arr = arr["KI"];
        msg->kI = kI_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'KI' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'KI' is wrong type; expected a double.");
    }
    try {
        //kD
        const matlab::data::TypedArray<double> kD_arr = arr["KD"];
        msg->kD = kD_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'KD' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'KD' is wrong type; expected a double.");
    }
    try {
        //obj_vel
        const matlab::data::TypedArray<double> obj_vel_arr = arr["ObjVel"];
        msg->obj_vel = obj_vel_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'ObjVel' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'ObjVel' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T wpg_msg_fuzzy_lcs_common::get_arr(MDFactory_T& factory, const wpg::fuzzy_lcs* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","KP","KI","KD","ObjVel"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("wpg/fuzzy_lcs");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // kP
    auto currentElement_kP = (msg + ctr)->kP;
    outArray[ctr]["KP"] = factory.createScalar(currentElement_kP);
    // kI
    auto currentElement_kI = (msg + ctr)->kI;
    outArray[ctr]["KI"] = factory.createScalar(currentElement_kI);
    // kD
    auto currentElement_kD = (msg + ctr)->kD;
    outArray[ctr]["KD"] = factory.createScalar(currentElement_kD);
    // obj_vel
    auto currentElement_obj_vel = (msg + ctr)->obj_vel;
    outArray[ctr]["ObjVel"] = factory.createScalar(currentElement_obj_vel);
    }
    return std::move(outArray);
  } 
class WPG_EXPORT wpg_fuzzy_lcs_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~wpg_fuzzy_lcs_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          wpg_fuzzy_lcs_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<wpg::fuzzy_lcs,wpg_msg_fuzzy_lcs_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         wpg_fuzzy_lcs_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<wpg::fuzzy_lcs,wpg::fuzzy_lcs::ConstPtr,wpg_msg_fuzzy_lcs_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         wpg_fuzzy_lcs_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<wpg::fuzzy_lcs,wpg_msg_fuzzy_lcs_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(wpg_msg_fuzzy_lcs_common, MATLABROSMsgInterface<wpg::fuzzy_lcs>)
CLASS_LOADER_REGISTER_CLASS(wpg_fuzzy_lcs_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1