cmake_minimum_required(VERSION 3.10)
project(wheatley VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(
    lodepng
    libs/lodepng/lodepng.cpp
    libs/lodepng/lodepng.h
)

include_directories(src/**)
add_executable(wheatley src/main.cc)
target_sources(wheatley
    PRIVATE 
        ${CMAKE_CURRENT_LIST_DIR}/src/image/image_op.cc
        ${CMAKE_CURRENT_LIST_DIR}/src/route_planner/PRM.cc
)
target_link_libraries(wheatley lodepng)
target_include_directories(wheatley PUBLIC libs)
target_include_directories(wheatley PUBLIC src)