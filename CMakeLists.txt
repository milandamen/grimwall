cmake_minimum_required(VERSION 2.6)
project(Grimwall)

# Add all files in src to be builded
file(GLOB_RECURSE Grimwall_SRC
    "src/*.h"
    "src/*.cpp"
)

# Add list of files to executable
add_executable(Grimwall ${Grimwall_SRC})

# Set flags for cmake about c++ version and debug/release warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
