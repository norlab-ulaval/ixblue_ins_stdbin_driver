#include "udp_listener.h"
#include <rclcpp/rclcpp.hpp>

std::string ip;
int udp_port;

class IxblueInsDriverNode : public rclcpp::Node
{
public:
    IxblueInsDriverNode():
        Node("ixblue_ins_driver")
    {
        this->declare_parameter<int>("udp_port", 8200);
        this->get_parameter("udp_port", udp_port);
        this->declare_parameter<std::string>("ip", "0.0.0.0");
        this->get_parameter("ip", ip);
        RCLCPP_INFO(this->get_logger(), "UDP port : %d", udp_port);
        RCLCPP_INFO(this->get_logger(), "IP adress : %s", ip.c_str());

        if(udp_port > std::numeric_limits<uint16_t>::max())
        {
            RCLCPP_ERROR_STREAM(this->get_logger(),
                    "UDP Port can't be greater than : " << std::numeric_limits<uint16_t>::max());
            rclcpp::shutdown();
        }
    }
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::Node::SharedPtr nh = std::make_shared<IxblueInsDriverNode>();
    UDPListener udpListener(ip, static_cast<uint16_t>(udp_port), nh);
    rclcpp::spin(nh);
    rclcpp::shutdown();
    return 0;
}
