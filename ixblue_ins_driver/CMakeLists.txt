cmake_minimum_required(VERSION 3.10.2)
project(ixblue_ins_driver)

set(CMAKE_BUILD_TYPE RelWithDebInfo)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ixblue_ins_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(diagnostic_updater REQUIRED)

## Specify libraries to link a library or executable target against
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

## System dependencies are found with CMake's conventions

# ixblue_stdbin_decoder must be set before Boost otherwise components are
# overridden (ixblue_stdbin_decoder only require system while we need
# program_options to build the packets replayer)
find_package(ixblue_stdbin_decoder REQUIRED)

find_package(Threads)

# the tests were not migrated for now
## PCAP and Boost program_options are used to build the packets replayer
## that is only used for development so build and requise it as dependency
## if tests are built
#if(CATKIN_ENABLE_TESTING)
#   find_package(PCAP REQUIRED)
#   find_package(Boost REQUIRED COMPONENTS system program_options)
#else()
   find_package(Boost REQUIRED COMPONENTS system)
#endif()

###########
## Build ##
###########

## Declare a C++ executable
aux_source_directory(src NODE_SRCS)
add_executable(${PROJECT_NAME}_node ${NODE_SRCS})
ament_target_dependencies(${PROJECT_NAME}_node rclcpp ixblue_ins_msgs ixblue_stdbin_decoder sensor_msgs diagnostic_updater)

#############
## Install ##
#############

## Mark executables and/or libraries for installation
install(TARGETS ${PROJECT_NAME}_node
    DESTINATION lib/${PROJECT_NAME}
)

## Mark other files for installation (e.g. launch and bag files, etc.)
install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)
# the tests were not migrated for now
##############
### Testing ##
##############
#
#if(CATKIN_ENABLE_TESTING)
#   add_executable(packets_replayer tools/packets_replayer.cpp)
#   target_link_libraries(packets_replayer ${PCAP_LIBRARY} ${Boost_LIBRARIES} Threads::Threads)
#
#   ## Add gtest based cpp test target and link libraries
#   catkin_add_gtest(${PROJECT_NAME}-test
#     test/test_ixblue_ins_driver.cpp
#     src/ros_publisher.cpp
#     src/diagnostics_publisher.cpp
#   )
#   if(TARGET ${PROJECT_NAME}-test)
#    target_link_libraries(${PROJECT_NAME}-test ${catkin_LIBRARIES} ${Boost_LIBRARIES} ixblue_stdbin_decoder::ixblue_stdbin_decoder)
#   endif()
#endif()

ament_package()
