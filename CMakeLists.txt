cmake_minimum_required(VERSION 3.10)

project(Cheap8)

include(cmake/tools.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL3 REQUIRED)

append_source(${CMAKE_CURRENT_LIST_DIR}/src cheap8_sources)

add_executable(Cheap8 ${cheap8_sources})

target_link_libraries(Cheap8 PRIVATE SDL3::SDL3)
