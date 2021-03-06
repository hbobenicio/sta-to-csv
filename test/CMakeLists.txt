cmake_minimum_required(VERSION 2.8.11)

find_package(GTest REQUIRED)

include_directories(
    "${CMAKE_SOURCE_DIR}/libsta/include"
    "${CMAKE_SOURCE_DIR}/vendor/nlohmann-json/2.0.9"
)

# Add all sources from the tested project into the TESTING_SOURCES list...
set (TESTING_SOURCES ${SOURCES})
# ... except 'main.cpp' because we are using a diffent main function for tests
#list(REMOVE_ITEM TESTING_SOURCES "${CMAKE_SOURCE_DIR}/src/main.cpp")

# EXCLUDE_FROM_ALL makes the 'tests' target optional, so it won't build when running just 'make'.
# You would need to run 'make tests' instead.
add_executable(tests EXCLUDE_FROM_ALL main-test.cpp ${TESTING_SOURCES})
add_dependencies(tests sta)
target_link_libraries(tests sta)

# Sets the library linking for the 'tests' target.
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)

# TODO Set fixtures as dependencies of the project
# TODO Make binary directory available for tests (independent of working directory)
file(GLOB FIXTURES "fixtures")
file(COPY ${FIXTURES} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
