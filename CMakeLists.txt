cmake_minimum_required(VERSION 2.8.10)
project(sta-to-csv)

# (use -DCMAKE_BUILD_TYPE=Release|Debug to change the build type)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -s")

# CPack configuraiton.
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_NAME "sta-to-csv")
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "1")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_DEBIAN_PACKAGE_VERSION "0.1.0")
set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "amd64")
SET(CPACK_SYSTEM_NAME "linux-amd64")
set(CPACK_PACKAGE_DESCRIPTION "STA to CSV - Conversor STA para CSV")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "STA to CSV - Conversor STA para CSV")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "STA to CSV - Conversor STA para CSV")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Hugo Benicio <hugo.oliveira@serpro.gov.br>")
set(CPACK_DEBIAN_PACKAGE_SECTION "devel")
set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
# set(CPACK_DEBIAN_PACKAGE_RECOMMENDS "")
# set(CPACK_DEBIAN_PACKAGE_SUGGESTS "")
# set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_SOURCE_DIR}/deb/usr/share/doc/pkg/copyright;")

include_directories(include)
include_directories(libsta/include)

file(GLOB SOURCES "src/*.cpp")

add_subdirectory(libsta)
add_subdirectory(test)

add_executable(sta-to-csv ${SOURCES})
add_dependencies(sta-to-csv sta)
target_link_libraries(sta-to-csv sta)

install(TARGETS sta-to-csv
        RUNTIME DESTINATION /usr/local/bin)

include(CPack)