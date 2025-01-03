// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for wpg/fuzzy
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
#include "wpg/fuzzy.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class WPG_EXPORT wpg_msg_fuzzy_common : public MATLABROSMsgInterface<wpg::fuzzy> {
  public:
    virtual ~wpg_msg_fuzzy_common(){}
    virtual void copy_from_struct(wpg::fuzzy* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const wpg::fuzzy* msg, MultiLibLoader loader, size_t size = 1);
};
  void wpg_msg_fuzzy_common::copy_from_struct(wpg::fuzzy* msg, const matlab::data::Struct& arr,
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
        //Error
        const matlab::data::TypedArray<double> Error_arr = arr["Error"];
        msg->Error = Error_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Error' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Error' is wrong type; expected a double.");
    }
    try {
        //D_Error
        const matlab::data::TypedArray<double> D_Error_arr = arr["DError"];
        msg->D_Error = D_Error_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DError' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DError' is wrong type; expected a double.");
    }
    try {
        //P_val
        const matlab::data::TypedArray<double> P_val_arr = arr["PVal"];
        msg->P_val = P_val_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'PVal' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'PVal' is wrong type; expected a double.");
    }
    try {
        //I_val
        const matlab::data::TypedArray<double> I_val_arr = arr["IVal"];
        msg->I_val = I_val_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'IVal' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'IVal' is wrong type; expected a double.");
    }
    try {
        //D_val
        const matlab::data::TypedArray<double> D_val_arr = arr["DVal"];
        msg->D_val = D_val_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'DVal' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'DVal' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T wpg_msg_fuzzy_common::get_arr(MDFactory_T& factory, const wpg::fuzzy* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","Error","DError","PVal","IVal","DVal"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("wpg/fuzzy");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // Error
    auto currentElement_Error = (msg + ctr)->Error;
    outArray[ctr]["Error"] = factory.createScalar(currentElement_Error);
    // D_Error
    auto currentElement_D_Error = (msg + ctr)->D_Error;
    outArray[ctr]["DError"] = factory.createScalar(currentElement_D_Error);
    // P_val
    auto currentElement_P_val = (msg + ctr)->P_val;
    outArray[ctr]["PVal"] = factory.createScalar(currentElement_P_val);
    // I_val
    auto currentElement_I_val = (msg + ctr)->I_val;
    outArray[ctr]["IVal"] = factory.createScalar(currentElement_I_val);
    // D_val
    auto currentElement_D_val = (msg + ctr)->D_val;
    outArray[ctr]["DVal"] = factory.createScalar(currentElement_D_val);
    }
    return std::move(outArray);
  } 
class WPG_EXPORT wpg_fuzzy_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~wpg_fuzzy_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          wpg_fuzzy_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<wpg::fuzzy,wpg_msg_fuzzy_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         wpg_fuzzy_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<wpg::fuzzy,wpg::fuzzy::ConstPtr,wpg_msg_fuzzy_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         wpg_fuzzy_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<wpg::fuzzy,wpg_msg_fuzzy_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(wpg_msg_fuzzy_common, MATLABROSMsgInterface<wpg::fuzzy>)
CLASS_LOADER_REGISTER_CLASS(wpg_fuzzy_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1