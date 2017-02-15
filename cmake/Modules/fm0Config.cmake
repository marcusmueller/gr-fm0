INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_FM0 fm0)

FIND_PATH(
    FM0_INCLUDE_DIRS
    NAMES fm0/api.h
    HINTS $ENV{FM0_DIR}/include
        ${PC_FM0_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    FM0_LIBRARIES
    NAMES gnuradio-fm0
    HINTS $ENV{FM0_DIR}/lib
        ${PC_FM0_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(FM0 DEFAULT_MSG FM0_LIBRARIES FM0_INCLUDE_DIRS)
MARK_AS_ADVANCED(FM0_LIBRARIES FM0_INCLUDE_DIRS)

