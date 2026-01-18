cmake_minimum_required(VERSION 3.16)

project(reservation_system_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

file(GLOB_RECURSE HEADERS
    include/*.h
)

file(GLOB_RECURSE UIS
    src/*.ui
)


add_executable(reservation_system_demo
    ${SOURCES}
    ${HEADERS}
    ${UIS}
)

target_include_directories(reservation_system_demo PRIVATE include)

target_link_libraries(reservation_system_demo PRIVATE Qt6::Widgets)