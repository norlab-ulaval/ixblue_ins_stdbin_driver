cmake_minimum_required(VERSION 3.10.2)
project(ixblue_ins_msgs)

find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Ins.msg"
  DEPENDENCIES geometry_msgs std_msgs
)

ament_package()
