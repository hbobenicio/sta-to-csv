cmake_minimum_required(VERSION 2.8.10)
project(sta-to-csv)

set (CMAKE_CXX_FLAGS "-std=c++14 -g -Wall")

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(sta-to-csv ${SOURCES})