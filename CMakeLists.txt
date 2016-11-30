#------------------------------------------------------------------------------
#                                 Grimwall
#------------------------------------------------------------------------------
# Note: This CMakeLists is based on fifengine/cpp-tutorials
#------------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.6)
project(Grimwall)

#------------------------------------------------------------------------------
#                                 Configure
#------------------------------------------------------------------------------

# set path to our custom CMAKE scripts
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/CMake/Modules")

# Create a "Release" build by default.
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
    "Select build type. Options are: 'Debug', 'Release', 'RelWithDebInfo' and 'MinSizeRel'."
    FORCE
  )
  message(STATUS "Set CMAKE_BUILD_TYPE to default '${CMAKE_BUILD_TYPE}'.")
endif(NOT CMAKE_BUILD_TYPE)

# Do not allow an in-source-tree build, request an out-of-source-tree build.
if (CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR "#Please build outside of the source tree!\n
                       Make a separate folder for building and run CMake there:\n
                       mkdir _build; cd _build; cmake ..\n
                       Before that, be sure to cleanup:\nrm -rf CMakeCache.txt CMakeFiles")
endif()

# Disable in-source builds and modifications to the source tree.
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

#------------------------------------------------------------------------------
#                                 Display Status
#------------------------------------------------------------------------------

message("")
message("== Building ${PROJECT_NAME} using build type '${CMAKE_BUILD_TYPE}'.")
message(STATUS "    Source directory is '${PROJECT_SOURCE_DIR}'.")
message(STATUS "    Build  directory is '${PROJECT_BINARY_DIR}'.")
message(STATUS "    Installation path is '${CMAKE_INSTALL_PREFIX}' (set -DCMAKE_INSTALL_PREFIX=<path> to change).")
message(STATUS "    CXX Compiler Flags: '${CMAKE_CXX_FLAGS}'.")
message(STATUS "    Dependencies folder: '${PROJECT_SOURCE_DIR}/dependencies'.")
message("")

#------------------------------------------------------------------------------
#                                 Compiler Options
#------------------------------------------------------------------------------

if(WIN32)

  if(MSVC)

    # ensure we use minimal "windows.h" lib without the crazy min max macros
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"WIN32_LEAN_AND_MEAN\"")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D \"NOMINMAX\"")

    # disable SAFESEH - to avoid "LNK2026: module unsafe" on "OpenAL32.lib"
    SET(CMAKE_CXX_FLAGS           "${CMAKE_CXX_FLAGS} /D \"SAFESEH:NO\"")
    SET(CMAKE_EXE_LINKER_FLAGS    "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SAFESEH:NO")
    SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} /SAFESEH:NO")

  endif(MSVC)

endif(WIN32)

#------------------------------------------------------------------------------
#                           Find Dependencies - Windows
#------------------------------------------------------------------------------

# Tell CMake where to search for binaries (dlls), includes and libs on Windows
if(WIN32)
  set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}
    "${PROJECT_SOURCE_DIR}/dependencies/bin"
    "${PROJECT_SOURCE_DIR}/dependencies/include"
    "${PROJECT_SOURCE_DIR}/dependencies/include/SDL2"
    "${PROJECT_SOURCE_DIR}/dependencies/include/OpenAL"
    "${PROJECT_SOURCE_DIR}/dependencies/lib/x86"
    "${PROJECT_SOURCE_DIR}/dependencies/lib"
    "${PROJECT_SOURCE_DIR}/dependencies/lib/boost"
  )
  set(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} ${CMAKE_PREFIX_PATH})
endif(WIN32)

#------------------------------------------------------------------------------
#                                 Configure Boost
#------------------------------------------------------------------------------

add_definitionS(-DBOOST_ALL_NO_LIB)

# use static libs
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)

#------------------------------------------------------------------------------
#                                Confifure Grimwall
#------------------------------------------------------------------------------

# Add all files in src/Domain to be builded
file(GLOB_RECURSE Grimwall_SRC_Domain
    "src/Domain/*.h"
    "src/Domain/*.cpp"
)
# Add all files in src/GUI to be builded
file(GLOB_RECURSE Grimwall_SRC_GUI
    "src/GUI/*.h"
    "src/GUI/*.cpp"
)
# Add all files in src/Input to be builded
file(GLOB_RECURSE Grimwall_SRC_Input
    "src/Input/*.h"
    "src/Input/*.cpp"
)

# Add list of files to executable
add_executable(Grimwall ${Grimwall_SRC_Domain} ${Grimwall_SRC_GUI} ${Grimwall_SRC_Input} "src/main.cpp" src/Input/Callbacks/TroupSpawnCallback.cpp src/Input/Callbacks/TroupSpawnCallback.h)

if(APPLE)
  find_package(Xcursor REQUIRED)
  target_link_libraries(Grimwall ${XCURSOR_LIBRARY})
  include(${XCURSOR_INCLUDE_DIR})
endif()

if(UNIX)
    find_package(X11 REQUIRED)
    target_link_libraries(Grimwall ${X11_LIBRARY})
    target_link_libraries(Grimwall Xcursor)
endif()

find_package(Fife REQUIRED)
find_package(FifeChan COMPONENTS opengl sdl REQUIRED)
find_package(Boost 1.33.1 COMPONENTS system filesystem regex)
find_package(Vorbis REQUIRED)
find_package(ZLIB REQUIRED)
find_package(PNG REQUIRED)
find_package(Ogg REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(OpenAL REQUIRED)
find_package(OpenGL REQUIRED)
find_package(TinyXML REQUIRED)

include_directories( 
    ${ZLIB_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR}
    ${OGG_INCLUDE_DIR}
    ${PNG_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    ${SDL2_INCLUDE_DIR}
    ${SDL2_TTF_INCLUDE_DIR}
    ${VORBIS_INCLUDE_DIR}   
    ${FIFE_INCLUDE_DIR}
    ${FIFECHAN_INCLUDE_DIR}
)

target_link_libraries(Grimwall ${ZLIB_LIBRARIES})
target_link_libraries(Grimwall ${Boost_LIBRARIES})
target_link_libraries(Grimwall ${OPENAL_LIBRARY})
target_link_libraries(Grimwall ${OPENGL_LIBRARY})
target_link_libraries(Grimwall ${PNG_LIBRARIES})
target_link_libraries(Grimwall ${SDL2_LIBRARY})
target_link_libraries(Grimwall ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(Grimwall ${SDL2_TTF_LIBRARIES})
target_link_libraries(Grimwall ${TinyXML_LIBRARIES})
target_link_libraries(Grimwall ${OGG_LIBRARIES})
target_link_libraries(Grimwall ${VORBIS_LIBRARIES})
target_link_libraries(Grimwall ${VORBIS_LIBRARY})
target_link_libraries(Grimwall ${VORBISFILE_LIBRARY})
target_link_libraries(Grimwall ${FIFECHAN_LIBRARIES})
target_link_libraries(Grimwall ${FIFE_LIBRARIES})

# Set flags for cmake about c++ version and debug/release warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

#------------------------------------------------------------------------------
#                              Install Grimwall                                
#------------------------------------------------------------------------------

# install the binary/exe into the subfolder "Grimwall"
install(TARGETS Grimwall     
    RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}
    COMPONENT executable
)

# if(WIN32)
# 
#     # set paths to executables
#     set(APP ${CMAKE_INSTALL_PREFIX}/Grimwall/Grimwall${CMAKE_EXECUTABLE_SUFFIX}) 
# 
#     # set paths to dependencies
#     set(DIRS ${PROJECT_SOURCE_DIR}/dependencies/bin
#              ${PROJECT_SOURCE_DIR}/dependencies/lib
#              ${PROJECT_SOURCE_DIR}/dependencies/lib/x86 
#     )   
# 
#     # copy all libraries to the binary folder
#     # by calling fixup_bundle, when TARGET INSTALL is executed
#     install(CODE "
#        include(BundleUtilities)
#        fixup_bundle(\"${APP}\"   \"\"   \"${DIRS}\")
#        " 
#        COMPONENT libraries
#     )
#     
# endif()

#------------------------------------------------------------------------------
#                        Copy assets
#------------------------------------------------------------------------------

# Based on http://stackoverflow.com/a/31518137

# Add custom target that always runs (it tries to find the file "${CMAKE_CURRENT_BINARY_DIR}/asset files" that doesn't exist)
add_custom_target(
    copy_assets ALL
    DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/asset files"
)

# Copy the assets
add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/asset files"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:Grimwall>/assets
)



# Packaging

# include system runtimes (e.g. msvcp140.dll) into "<install_prefix>/bin" folder 
# how can i change/remove the "bin" suffix to install into <install_prefix>?
#include(InstallRequiredSystemLibraries)



#------------------------------------------------------------------------------
#                        Google Test
#------------------------------------------------------------------------------

# To compile tests, run cmake with option: -DTESTS:BOOL=ON
set(TESTS OFF CACHE BOOL "Compile tests")
if(TESTS)
    # Add all files in src/Domain to be builded
    file(GLOB_RECURSE Grimwall_Test_SRC
        "test/src/*.cpp"
    )
    add_executable(Grimwall_Test ${Grimwall_SRC_Domain} ${Grimwall_SRC_GUI} ${Grimwall_SRC_Input} ${Grimwall_Test_SRC})

    if(APPLE)
        target_link_libraries(Grimwall_Test ${XCURSOR_LIBRARY})
        include(${XCURSOR_INCLUDE_DIR})
    endif()

    if(UNIX)
        target_link_libraries(Grimwall_Test ${X11_LIBRARY})
        target_link_libraries(Grimwall_Test Xcursor)
    endif()
    
    find_package(GoogleTest REQUIRED)
    
    include_directories(
        ${GTEST_INCLUDE_DIR}
    )

    target_link_libraries(Grimwall_Test ${ZLIB_LIBRARIES})
    target_link_libraries(Grimwall_Test ${Boost_LIBRARIES})
    target_link_libraries(Grimwall_Test ${OPENAL_LIBRARY})
    target_link_libraries(Grimwall_Test ${OPENGL_LIBRARY})
    target_link_libraries(Grimwall_Test ${PNG_LIBRARIES})
    target_link_libraries(Grimwall_Test ${SDL2_LIBRARY})
    target_link_libraries(Grimwall_Test ${SDL2_IMAGE_LIBRARIES})
    target_link_libraries(Grimwall_Test ${SDL2_TTF_LIBRARIES})
    target_link_libraries(Grimwall_Test ${TinyXML_LIBRARIES})
    target_link_libraries(Grimwall_Test ${OGG_LIBRARIES})
    target_link_libraries(Grimwall_Test ${VORBIS_LIBRARIES})
    target_link_libraries(Grimwall_Test ${VORBIS_LIBRARY})
    target_link_libraries(Grimwall_Test ${VORBISFILE_LIBRARY})
    target_link_libraries(Grimwall_Test ${FIFECHAN_LIBRARIES})
    target_link_libraries(Grimwall_Test ${FIFE_LIBRARIES})
    target_link_libraries(Grimwall_Test ${GTEST_LIBRARIES})

    install(TARGETS Grimwall_Test
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}
        COMPONENT executable
    )
endif(TESTS)