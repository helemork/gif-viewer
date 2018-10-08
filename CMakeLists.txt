cmake_minimum_required(VERSION 3.1)
project(cpp-basics)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# get path to logo images that isnt fixed
add_definitions("-DROOT_PATH=\"${CMAKE_SOURCE_DIR}/\"")

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)
add_executable(cpp-basics main.cpp)

# Use the Widgets module from Qt 5
target_link_libraries(cpp-basics Qt5::Widgets)