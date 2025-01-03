// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for wpg/defuzzyfied
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
#include "wpg/defuzzyfied.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class WPG_EXPORT wpg_msg_defuzzyfied_common : public MATLABROSMsgInterface<wpg::defuzzyfied> {
  public:
    virtual ~wpg_msg_defuzzyfied_common(){}
    virtual void copy_from_struct(wpg::defuzzyfied* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const wpg::defuzzyfied* msg, MultiLibLoader loader, size_t size = 1);
};
  void wpg_msg_defuzzyfied_common::copy_from_struct(wpg::defuzzyfied* msg, const matlab::data::Struct& arr,
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
        //Delta_P_val
        const matlab::data::TypedArray<double> Delta_P_val_arr = arr["DeltaPVal"];
        msg->Delta_P_val = Delta_P_val_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DeltaPVal' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DeltaPVal' is wrong type; expected a double.");
    }
    try {
        //Delta_I_val
        const matlab::data::TypedArray<double> Delta_I_val_arr = arr["DeltaIVal"];
        msg->Delta_I_val = Delta_I_val_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DeltaIVal' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DeltaIVal' is wrong type; expected a double.");
    }
    try {
        //Delta_D_val
        const matlab::data::TypedArray<double> Delta_D_val_arr = arr["DeltaDVal"];
        msg->Delta_D_val = Delta_D_val_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DeltaDVal' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DeltaDVal' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T wpg_msg_defuzzyfied_common::get_arr(MDFactory_T& factory, const wpg::defuzzyfied* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","DeltaPVal","DeltaIVal","DeltaDVal"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("wpg/defuzzyfied");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // Delta_P_val
    auto currentElement_Delta_P_val = (msg + ctr)->Delta_P_val;
    outArray[ctr]["DeltaPVal"] = factory.createScalar(currentElement_Delta_P_val);
    // Delta_I_val
    auto currentElement_Delta_I_val = (msg + ctr)->Delta_I_val;
    outArray[ctr]["DeltaIVal"] = factory.createScalar(currentElement_Delta_I_val);
    // Delta_D_val
    auto currentElement_Delta_D_val = (msg + ctr)->Delta_D_val;
    outArray[ctr]["DeltaDVal"] = factory.createScalar(currentElement_Delta_D_val);
    }
    return std::move(outArray);
  } 
class WPG_EXPORT wpg_defuzzyfied_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~wpg_defuzzyfied_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          wpg_defuzzyfied_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<wpg::defuzzyfied,wpg_msg_defuzzyfied_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         wpg_defuzzyfied_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<wpg::defuzzyfied,wpg::defuzzyfied::ConstPtr,wpg_msg_defuzzyfied_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         wpg_defuzzyfied_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<wpg::defuzzyfied,wpg_msg_defuzzyfied_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(wpg_msg_defuzzyfied_common, MATLABROSMsgInterface<wpg::defuzzyfied>)
CLASS_LOADER_REGISTER_CLASS(wpg_defuzzyfied_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1