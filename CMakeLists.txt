cmake_minimum_required(VERSION 2.6)
project(Grimwall)

file(GLOB Grimwall_SRC
    "*.h"
    "*.cpp"
)

add_executable(Grimwall ${Grimwall_SRC})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
