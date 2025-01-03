// Copyright 2019-2021 The MathWorks, Inc.
// Common copy functions for wpg/defuzzy_vel_modif
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
#include "wpg/defuzzy_vel_modif.h"
#include "visibility_control.h"
#include "MATLABROSMsgInterface.hpp"
#include "ROSPubSubTemplates.hpp"
class WPG_EXPORT wpg_msg_defuzzy_vel_modif_common : public MATLABROSMsgInterface<wpg::defuzzy_vel_modif> {
  public:
    virtual ~wpg_msg_defuzzy_vel_modif_common(){}
    virtual void copy_from_struct(wpg::defuzzy_vel_modif* msg, const matlab::data::Struct& arr, MultiLibLoader loader); 
    //----------------------------------------------------------------------------
    virtual MDArray_T get_arr(MDFactory_T& factory, const wpg::defuzzy_vel_modif* msg, MultiLibLoader loader, size_t size = 1);
};
  void wpg_msg_defuzzy_vel_modif_common::copy_from_struct(wpg::defuzzy_vel_modif* msg, const matlab::data::Struct& arr,
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
        //new_velocity
        const matlab::data::TypedArray<double> new_velocity_arr = arr["NewVelocity"];
        msg->new_velocity = new_velocity_arr[0];
    } catch (matlab::data::InvalidFieldNameException&) {
        throw std::invalid_argument("Field 'NewVelocity' is missing.");
    } catch (matlab::Exception&) {
        throw std::invalid_argument("Field 'NewVelocity' is wrong type; expected a double.");
    }
  }
  //----------------------------------------------------------------------------
  MDArray_T wpg_msg_defuzzy_vel_modif_common::get_arr(MDFactory_T& factory, const wpg::defuzzy_vel_modif* msg,
       MultiLibLoader loader, size_t size) {
    auto outArray = factory.createStructArray({size,1},{"MessageType","Header","NewVelocity"});
    for(size_t ctr = 0; ctr < size; ctr++){
    outArray[ctr]["MessageType"] = factory.createCharArray("wpg/defuzzy_vel_modif");
    // header
    auto currentElement_header = (msg + ctr)->header;
    auto msgClassPtr_header = getCommonObject<std_msgs::Header>("std_msgs_msg_Header_common",loader);
    outArray[ctr]["Header"] = msgClassPtr_header->get_arr(factory, &currentElement_header, loader);
    // new_velocity
    auto currentElement_new_velocity = (msg + ctr)->new_velocity;
    outArray[ctr]["NewVelocity"] = factory.createScalar(currentElement_new_velocity);
    }
    return std::move(outArray);
  } 
class WPG_EXPORT wpg_defuzzy_vel_modif_message : public ROSMsgElementInterfaceFactory {
  public:
    virtual ~wpg_defuzzy_vel_modif_message(){}
    virtual std::shared_ptr<MATLABPublisherInterface> generatePublisherInterface(ElementType type);
    virtual std::shared_ptr<MATLABSubscriberInterface> generateSubscriberInterface(ElementType type);
    virtual std::shared_ptr<MATLABRosbagWriterInterface> generateRosbagWriterInterface(ElementType type);
};  
  std::shared_ptr<MATLABPublisherInterface> 
          wpg_defuzzy_vel_modif_message::generatePublisherInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSPublisherImpl<wpg::defuzzy_vel_modif,wpg_msg_defuzzy_vel_modif_common>>();
  }
  std::shared_ptr<MATLABSubscriberInterface> 
         wpg_defuzzy_vel_modif_message::generateSubscriberInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSSubscriberImpl<wpg::defuzzy_vel_modif,wpg::defuzzy_vel_modif::ConstPtr,wpg_msg_defuzzy_vel_modif_common>>();
  }
#include "ROSbagTemplates.hpp" 
  std::shared_ptr<MATLABRosbagWriterInterface>
         wpg_defuzzy_vel_modif_message::generateRosbagWriterInterface(ElementType type){
    if(type != eMessage){
        throw std::invalid_argument("Wrong input, Expected eMessage");
    }
    return std::make_shared<ROSBagWriterImpl<wpg::defuzzy_vel_modif,wpg_msg_defuzzy_vel_modif_common>>();
  }
#include "register_macro.hpp"
// Register the component with class_loader.
// This acts as a sort of entry point, allowing the component to be discoverable when its library
// is being loaded into a running process.
CLASS_LOADER_REGISTER_CLASS(wpg_msg_defuzzy_vel_modif_common, MATLABROSMsgInterface<wpg::defuzzy_vel_modif>)
CLASS_LOADER_REGISTER_CLASS(wpg_defuzzy_vel_modif_message, ROSMsgElementInterfaceFactory)
#ifdef _MSC_VER
#pragma warning(pop)
#else
#pragma GCC diagnostic pop
#endif //_MSC_VER
//gen-1