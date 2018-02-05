set(CMAKE_EXPORT_COMPILE_COMMANDS 1 )
set(CMAKE_VERBOSE_MAKEFILE TRUE)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -W -Wno-unused-parameter")

cmake_minimum_required(VERSION 2.4.6)
project(BagFromImages)
set(OpenCV_DIR /opt/ros/kinetic/share/OpenCV-3.3.1)

set(CMAKE_CXX_STANDARD 11)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    rosbag
    cv_bridge
    image_transport
    OpenCV
    sensor_msgs
)

FIND_PACKAGE(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS
    system
    filesystem
)
find_package(PkgConfig)

catkin_package()

include_directories(
    ThirdParty/DLib
    ${catkin_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
)

add_library(FileFunctions Thirdparty/DLib/FileFunctions.cpp)
target_link_libraries(FileFunctions
    ${catkin_LIBRARIES}
    ${OpenCV_LIBRARIES}
)

add_executable(main main.cc)
target_link_libraries(main
    FileFunctions
    ${catkin_LIBRARIES}
    ${OpenCV_LIBRARIES}
)
