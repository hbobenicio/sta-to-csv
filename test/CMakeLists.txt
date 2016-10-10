cmake_minimum_required(VERSION 2.8)

find_package(GTest REQUIRED)

set (TESTING_SOURCES ${SOURCES})
list(REMOVE_ITEM TESTING_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_executable(tests EXCLUDE_FROM_ALL main-test.cpp ${TESTING_SOURCES})

target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
