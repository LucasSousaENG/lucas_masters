// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for wpg/defuzzy_lcs
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
#include "wpg/defuzzy_lcs.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class WPG_EXPORT wpg_msg_defuzzy_lcs_common : public MATLABROSMsgInterface<wpg::defuzzy_lcs> {
  public:
    virtual ~wpg_msg_defuzzy_lcs_common(){}
    virtual void copy_from_struct(wpg::defuzzy_lcs* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const wpg::defuzzy_lcs* msg, MultiLibLoader loader, size_t size = 1);
};
  void wpg_msg_defuzzy_lcs_common::copy_from_struct(wpg::defuzzy_lcs* msg, const matlab::data::Struct& arr,
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
        //New_P
        const matlab::data::TypedArray<double> New_P_arr = arr["NewP"];
        msg->New_P = New_P_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'NewP' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'NewP' is wrong type; expected a double.");
    }
    try {
        //New_I
        const matlab::data::TypedArray<double> New_I_arr = arr["NewI"];
        msg->New_I = New_I_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'NewI' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'NewI' is wrong type; expected a double.");
    }
    try {
        //New_D
        const matlab::data::TypedArray<double> New_D_arr = arr["NewD"];
        msg->New_D = New_D_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'NewD' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'NewD' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T wpg_msg_defuzzy_lcs_common::get_arr(MDFactory_T& factory, const wpg::defuzzy_lcs* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","NewP","NewI","NewD"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("wpg/defuzzy_lcs");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // New_P
    auto currentElement_New_P = (msg + ctr)->New_P;
    outArray[ctr]["NewP"] = factory.createScalar(currentElement_New_P);
    // New_I
    auto currentElement_New_I = (msg + ctr)->New_I;
    outArray[ctr]["NewI"] = factory.createScalar(currentElement_New_I);
    // New_D
    auto currentElement_New_D = (msg + ctr)->New_D;
    outArray[ctr]["NewD"] = factory.createScalar(currentElement_New_D);
    }
    return std::move(outArray);
  } 
class WPG_EXPORT wpg_defuzzy_lcs_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~wpg_defuzzy_lcs_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          wpg_defuzzy_lcs_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<wpg::defuzzy_lcs,wpg_msg_defuzzy_lcs_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         wpg_defuzzy_lcs_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<wpg::defuzzy_lcs,wpg::defuzzy_lcs::ConstPtr,wpg_msg_defuzzy_lcs_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         wpg_defuzzy_lcs_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<wpg::defuzzy_lcs,wpg_msg_defuzzy_lcs_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(wpg_msg_defuzzy_lcs_common, MATLABROSMsgInterface<wpg::defuzzy_lcs>)
CLASS_LOADER_REGISTER_CLASS(wpg_defuzzy_lcs_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1