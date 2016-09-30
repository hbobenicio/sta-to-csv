cmake_minimum_required(VERSION 2.8.10)
project(sta-to-csv)

# Configure it according to build profile
#set (CMAKE_CXX_FLAGS "-std=c++14 -O0 -g -Wall")
set (CMAKE_CXX_FLAGS "-std=c++14 -O2 -s -Wall")

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(sta-to-csv ${SOURCES})

install(TARGETS sta-to-csv RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_NAME "sta-to-csv")
#set(CPACK_PACKAGE_VERSION_MAJOR "0")
#set(CPACK_PACKAGE_VERSION_MINOR "1")
#set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_DEBIAN_PACKAGE_VERSION "0.1")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")

# Configure it according to build system
SET(CPACK_SYSTEM_NAME "linux-amd64")

#set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "STA to CSV - Conversor STA para CSV")
set(CPACK_PACKAGE_DESCRIPTION "STA to CSV - Conversor STA para CSV")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "STA to CSV - Conversor STA para CSV")

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Hugo Benicio <hugo.oliveira@serpro.gov.br>")
set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
#set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/Debian/postinst")

include(CPack)