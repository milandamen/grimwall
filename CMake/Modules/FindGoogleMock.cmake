#------------------------------------------------------------------------------
# FindGoogleMock.cmake
#------------------------------------------------------------------------------
#
# Find the native gmock includes and libraries.
#
# GMOCK_INCLUDE_DIR  - where to find gmock/gmock.h, etc.
# GMOCK_LIBRARIES    - List of libraries when using gmock.
# GMOCK_FOUND        - True, if gmock found.
#
#------------------------------------------------------------------------------
# Author: Groep B, Avans 2016
# Original Author: Jens A. Koch <jakoch@web.de> for FIFE
#------------------------------------------------------------------------------

if(GMOCK_INCLUDE_DIR)
    # Already in cache, be silent
    set(GMOCK_FIND_QUIETLY TRUE)
endif(GMOCK_INCLUDE_DIR)

find_path(GMOCK_INCLUDE_DIR gmock/gmock.h)

# append "gmock" to "include" path
set(GMOCK_INCLUDE_DIR ${GMOCK_INCLUDE_DIR}/gmock)


# The provided project files name the library with the lib prefix.
find_library(GMOCK_LIBRARY NAMES gmock)

# Handle the QUIETLY and REQUIRED arguments and set GMOCK_FOUND
# to TRUE if all listed variables are TRUE.
include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(GMOCK 
    REQUIRED_VARS GMOCK_LIBRARY GMOCK_INCLUDE_DIR
)

if(GMOCK_FOUND)
    set(GMOCK_LIBRARIES ${GMOCK_LIBRARY})
endif(GMOCK_FOUND)

mark_as_advanced(GMOCK_INCLUDE_DIR GMOCK_LIBRARY)
