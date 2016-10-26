cmake_minimum_required(VERSION 3.1)
project(qt-chess LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC On)
set(CMAKE_INCLUDE_CURRENT_DIR On)

find_package(Qt5 5.5.0 CONFIG REQUIRED Widgets Svg Qml Quick)

add_subdirectory(src)
