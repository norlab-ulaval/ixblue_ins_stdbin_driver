#pragma once

#include <ixblue_ins_msgs/msg/ins.hpp>
#include <ixblue_stdbin_decoder/data_models/nav_header.h>
#include <ixblue_stdbin_decoder/data_models/stdbin.h>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <sensor_msgs/msg/nav_sat_fix.hpp>
#include <sensor_msgs/msg/time_reference.hpp>

#include "diagnostics_publisher.h"

class ROSPublisher
{
public:
    ROSPublisher(rclcpp::Node::SharedPtr nh);
    void onNewStdBinData(const ixblue_stdbin_decoder::Data::BinaryNav& navData,
                         const ixblue_stdbin_decoder::Data::NavHeader& headerData);

    // Standard ros msgs
    sensor_msgs::msg::Imu::SharedPtr
    toImuMsg(const ixblue_stdbin_decoder::Data::BinaryNav& navData,
             bool use_compensated_acceleration);
    sensor_msgs::msg::NavSatFix::SharedPtr
    toNavSatFixMsg(const ixblue_stdbin_decoder::Data::BinaryNav& navData);
    sensor_msgs::msg::TimeReference::SharedPtr
    toTimeReference(const ixblue_stdbin_decoder::Data::NavHeader& headerData);

    // iXblue ros msgs
    ixblue_ins_msgs::msg::Ins::SharedPtr
    toiXInsMsg(const ixblue_stdbin_decoder::Data::BinaryNav& navData);

protected:
    // Header
    std_msgs::msg::Header getHeader(const ixblue_stdbin_decoder::Data::NavHeader& headerData,
                               const ixblue_stdbin_decoder::Data::BinaryNav& navData);

    // Launch parameters
    std::string frame_id;
    std::string time_source;
    std::string time_origin;
    bool use_compensated_acceleration;

    rclcpp::Node::SharedPtr nh;

    // Publishers
    rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr stdImuPublisher;
    rclcpp::Publisher<sensor_msgs::msg::NavSatFix>::SharedPtr stdNavSatFixPublisher;
    rclcpp::Publisher<sensor_msgs::msg::TimeReference>::SharedPtr stdTimeReferencePublisher;
    rclcpp::Publisher<ixblue_ins_msgs::msg::Ins>::SharedPtr stdInsPublisher;
    DiagnosticsPublisher diagPub;

    // Utils
    bool useInsAsTimeReference = true;
    bool useUnixAsTimeOrigin = true;
};
