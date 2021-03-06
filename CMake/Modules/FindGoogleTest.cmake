#------------------------------------------------------------------------------
# FindGoogleTest.cmake
#------------------------------------------------------------------------------
#
# Find the native gtest includes and libraries.
#
# GTEST_INCLUDE_DIR  - where to find gtest/gtest.h, etc.
# GTEST_LIBRARIES    - List of libraries when using gtest.
# GTEST_FOUND        - True, if gtest found.
#
#------------------------------------------------------------------------------
# Author: Groep B, Avans 2016
# Original Author: Jens A. Koch <jakoch@web.de> for FIFE
#------------------------------------------------------------------------------

if(GTEST_INCLUDE_DIR)
    # Already in cache, be silent
    set(GTEST_FIND_QUIETLY TRUE)
endif(GTEST_INCLUDE_DIR)

find_path(GTEST_INCLUDE_DIR gtest/gtest.h)

# append "gtest" to "include" path
set(GTEST_INCLUDE_DIR ${GTEST_INCLUDE_DIR}/gtest)


# The provided project files name the library with the lib prefix.
find_library(GTEST_LIBRARY NAMES gtest)

# Handle the QUIETLY and REQUIRED arguments and set GTEST_FOUND
# to TRUE if all listed variables are TRUE.
include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(GTEST 
    REQUIRED_VARS GTEST_LIBRARY GTEST_INCLUDE_DIR
)

if(GTEST_FOUND)
    set(GTEST_LIBRARIES ${GTEST_LIBRARY})
endif(GTEST_FOUND)

mark_as_advanced(GTEST_INCLUDE_DIR GTEST_LIBRARY)
