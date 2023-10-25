#include "udp_listener.h"
#include <boost/bind.hpp>

using namespace boost::asio;

UDPListener::UDPListener(const std::string& ip, uint16_t port, rclcpp::Node::SharedPtr nh)
    : IPListener(ip, port, nh),
      socket(service, ip::udp::endpoint(ip::address::from_string(ip), port))
{
    listenNextData();
    RCLCPP_DEBUG_STREAM(nh->get_logger(), "Starting asio thread");
    asioThread = std::thread([&]() { service.run(); });
}

void UDPListener::listenNextData()
{
    socket.async_receive_from(boost::asio::buffer(datas), endpoint,
                              boost::bind(&IPListener::onNewDataReceived, this,
                                          boost::asio::placeholders::error,
                                          boost::asio::placeholders::bytes_transferred));
}
