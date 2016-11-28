cmake_minimum_required(VERSION 2.8.10)
project(sta-to-csv)

# (use -DCMAKE_BUILD_TYPE=Release|Debug to change the build type)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -s")

add_subdirectory(libsta)
add_subdirectory(cli)
add_subdirectory(test)
