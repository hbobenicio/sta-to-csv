cmake_minimum_required(VERSION 3.0.2)
project(gui)

# Widgets finds its own dependencies.
#find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(AUTOUIC_SEARCH_PATHS "ui")

#qt5_wrap_ui(${CMAKE_BINARY_DIR}/ui/ui_sta_to_csv_dialog.h)
#QT5_WRAP_UI(image_result_matrix.h ui_forms/image_result_matrix.ui -o ui_forms/image_result_matrix.h)

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB GUI_HEADERS "include/*.h")
file(GLOB GUI_SOURCES "src/*.cpp" "ui/*.ui")
file(GLOB GUI_FORMS "ui/*.ui")

include_directories(
    "include"
    "${CMAKE_SOURCE_DIR}/libsta/include"
    "${CMAKE_SOURCE_DIR}/vendor/nlohmann-json/2.0.9"
)

add_executable(gui "${GUI_SOURCES}")
add_dependencies(gui sta)
target_link_libraries(gui sta Qt5::Widgets)
#qt5_use_modules(gui Core Widgets)

install(TARGETS gui DESTINATION /usr/local/bin)
