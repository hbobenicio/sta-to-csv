cmake_minimum_required(VERSION 2.8.10)
project(libsta)

file(GLOB LIBSTA_HEADERS "include/*.h")
file(GLOB LIBSTA_SOURCES "src/*.cpp")

include_directories(include)

add_library(sta STATIC ${LIBSTA_SOURCES})
add_library(sta_shared SHARED ${LIBSTA_SOURCES}) # rename to libsta.so

set_target_properties(sta PROPERTIES PUBLIC_HEADER "${LIBSTA_HEADERS}")

# /usr/lib ?
install(TARGETS sta sta_shared
        ARCHIVE DESTINATION /usr/local/lib
        LIBRARY DESTINATION /usr/local/lib
        PUBLIC_HEADER DESTINATION /usr/local/include/sta)
