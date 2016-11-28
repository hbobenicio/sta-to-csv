cmake_minimum_required(VERSION 2.8.10)
project(cli)

file(GLOB CLI_HEADERS "include/*.h")
file(GLOB CLI_SOURCES "src/*.cpp")

include_directories("include" "${CMAKE_SOURCE_DIR}/libsta/include")

# EXCLUDE_FROM_ALL makes the 'tests' target optional, so it won't build when running just 'make'.
# You would need to run 'make tests' instead.
add_executable(cli "${CLI_SOURCES}")
add_dependencies(cli sta)
target_link_libraries(cli sta)

install(TARGETS cli DESTINATION /usr/local/bin)

