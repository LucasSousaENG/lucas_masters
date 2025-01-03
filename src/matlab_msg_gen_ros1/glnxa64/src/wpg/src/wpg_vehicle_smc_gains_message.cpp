// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for wpg/vehicle_smc_gains
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
#include "wpg/vehicle_smc_gains.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class WPG_EXPORT wpg_msg_vehicle_smc_gains_common : public MATLABROSMsgInterface<wpg::vehicle_smc_gains> {
  public:
    virtual ~wpg_msg_vehicle_smc_gains_common(){}
    virtual void copy_from_struct(wpg::vehicle_smc_gains* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const wpg::vehicle_smc_gains* msg, MultiLibLoader loader, size_t size = 1);
};
  void wpg_msg_vehicle_smc_gains_common::copy_from_struct(wpg::vehicle_smc_gains* msg, const matlab::data::Struct& arr,
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
        //timestamp
        const matlab::data::TypedArray<uint64_t> timestamp_arr = arr["Timestamp"];
        msg->timestamp = timestamp_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'Timestamp' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'Timestamp' is wrong type; expected a uint64.");
    }
    try {
        //timestamp_sample
        const matlab::data::TypedArray<uint64_t> timestamp_sample_arr = arr["TimestampSample"];
        msg->timestamp_sample = timestamp_sample_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'TimestampSample' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'TimestampSample' is wrong type; expected a uint64.");
    }
    try {
        //k_gains
        const matlab::data::TypedArray<float> k_gains_arr = arr["KGains"];
        size_t nelem = 3;
        	std::copy(k_gains_arr.begin(), k_gains_arr.begin()+nelem, msg->k_gains.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'KGains' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'KGains' is wrong type; expected a single.");
    }
    try {
        //beta_gains
        const matlab::data::TypedArray<float> beta_gains_arr = arr["BetaGains"];
        size_t nelem = 3;
        	std::copy(beta_gains_arr.begin(), beta_gains_arr.begin()+nelem, msg->beta_gains.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'BetaGains' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'BetaGains' is wrong type; expected a single.");
    }
    try {
        //lambda_gains
        const matlab::data::TypedArray<float> lambda_gains_arr = arr["LambdaGains"];
        size_t nelem = 3;
        	std::copy(lambda_gains_arr.begin(), lambda_gains_arr.begin()+nelem, msg->lambda_gains.begin());
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'LambdaGains' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'LambdaGains' is wrong type; expected a single.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T wpg_msg_vehicle_smc_gains_common::get_arr(MDFactory_T& factory, const wpg::vehicle_smc_gains* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","Timestamp","TimestampSample","KGains","BetaGains","LambdaGains"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("wpg/vehicle_smc_gains");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // timestamp
    auto currentElement_timestamp = (msg + ctr)->timestamp;
    outArray[ctr]["Timestamp"] = factory.createScalar(currentElement_timestamp);
    // timestamp_sample
    auto currentElement_timestamp_sample = (msg + ctr)->timestamp_sample;
    outArray[ctr]["TimestampSample"] = factory.createScalar(currentElement_timestamp_sample);
    // k_gains
    auto currentElement_k_gains = (msg + ctr)->k_gains;
    outArray[ctr]["KGains"] = factory.createArray<wpg::vehicle_smc_gains::_k_gains_type::const_iterator, float>({currentElement_k_gains.size(),1}, currentElement_k_gains.begin(), currentElement_k_gains.end());
    // beta_gains
    auto currentElement_beta_gains = (msg + ctr)->beta_gains;
    outArray[ctr]["BetaGains"] = factory.createArray<wpg::vehicle_smc_gains::_beta_gains_type::const_iterator, float>({currentElement_beta_gains.size(),1}, currentElement_beta_gains.begin(), currentElement_beta_gains.end());
    // lambda_gains
    auto currentElement_lambda_gains = (msg + ctr)->lambda_gains;
    outArray[ctr]["LambdaGains"] = factory.createArray<wpg::vehicle_smc_gains::_lambda_gains_type::const_iterator, float>({currentElement_lambda_gains.size(),1}, currentElement_lambda_gains.begin(), currentElement_lambda_gains.end());
    }
    return std::move(outArray);
  } 
class WPG_EXPORT wpg_vehicle_smc_gains_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~wpg_vehicle_smc_gains_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          wpg_vehicle_smc_gains_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<wpg::vehicle_smc_gains,wpg_msg_vehicle_smc_gains_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         wpg_vehicle_smc_gains_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<wpg::vehicle_smc_gains,wpg::vehicle_smc_gains::ConstPtr,wpg_msg_vehicle_smc_gains_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         wpg_vehicle_smc_gains_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<wpg::vehicle_smc_gains,wpg_msg_vehicle_smc_gains_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(wpg_msg_vehicle_smc_gains_common, MATLABROSMsgInterface<wpg::vehicle_smc_gains>)
CLASS_LOADER_REGISTER_CLASS(wpg_vehicle_smc_gains_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1