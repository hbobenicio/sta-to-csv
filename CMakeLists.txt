cmake_minimum_required(VERSION 2.8.11)
project(sta-to-csv)

# (use -DCMAKE_BUILD_TYPE=Release|Debug to change the build type)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -s")

add_subdirectory(libsta)
add_subdirectory(cli)
add_subdirectory(gui)
add_subdirectory(test)
