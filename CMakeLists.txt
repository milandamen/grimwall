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

# Add all files in src to be builded
file(GLOB_RECURSE Grimwall_SRC
    "src/*.h"
    "src/*.cpp"
)

# Add list of files to executable
add_executable(Grimwall ${Grimwall_SRC} src/Domain/Units/Heroes/Horwen.cpp src/Domain/Units/Heroes/Horwen.h src/Domain/Units/Heroes/Abilities/StrikeOfReflection.h src/Domain/Units/Heroes/Abilities/Rage.h src/Domain/Units/Heroes/Abilities/Execution.h src/Domain/Units/Heroes/Abilities/ShieldOfJustice.h src/Domain/Units/Heroes/Abilities/Execution.cpp src/Domain/Units/Heroes/Abilities/Rage.cpp src/Domain/Units/Heroes/Abilities/ShieldOfJustice.cpp src/Domain/Units/Heroes/Abilities/StrikeOfReflection.cpp src/Domain/Units/Buff/ExecutionBuff.h src/Domain/Units/Buff/RageBuff.h src/Domain/Units/Buff/RageBuff.cpp)

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

add_custom_command(TARGET Grimwall POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:Grimwall>/assets)



# Packaging

# include system runtimes (e.g. msvcp140.dll) into "<install_prefix>/bin" folder 
# how can i change/remove the "bin" suffix to install into <install_prefix>?
#include(InstallRequiredSystemLibraries)