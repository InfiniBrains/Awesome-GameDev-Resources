# ensure the user has git installed
find_package(Git)
if(Git_FOUND)
  message(STATUS "Git found: ${GIT_EXECUTABLE}")
else()
  message(FATAL "Git not found. Please install git before continuing. This project needs git in your path in order to work properly.")
endif()

# find latest version of CPM
IF(NOT (EXISTS ${CMAKE_BINARY_DIR}/cmake.release.json))
  message(STATUS "Fetching CPM latest release")
  file(DOWNLOAD
        "https://api.github.com/repos/cpm-cmake/CPM.cmake/releases/latest"
        "${CMAKE_BINARY_DIR}/cmake.release.json"
        SHOW_PROGRESS
  )
endif()
file(READ "${CMAKE_BINARY_DIR}/cmake.release.json" CPM_RELEASE)
string(JSON CPM_DOWNLOAD_VERSION GET ${CPM_RELEASE} tag_name)
message(STATUS "Using CPM version ${CPM_DOWNLOAD_VERSION}")

# Set CPM module download location
if(CPM_SOURCE_CACHE)
  set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
elseif(DEFINED ENV{CPM_SOURCE_CACHE})
  set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
else()
  set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
endif()

# Expand relative path. This is important if the provided path contains a tilde (~)
get_filename_component(CPM_DOWNLOAD_LOCATION ${CPM_DOWNLOAD_LOCATION} ABSOLUTE)

function(download_cpm)
  message(STATUS "Downloading CPM.cmake to ${CPM_DOWNLOAD_LOCATION}")
  file(DOWNLOAD
       https://github.com/cpm-cmake/CPM.cmake/releases/download/${CPM_DOWNLOAD_VERSION}/CPM.cmake
       ${CPM_DOWNLOAD_LOCATION}
  )
endfunction()

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
  download_cpm()
else()
  # resume download if it previously failed
  file(READ ${CPM_DOWNLOAD_LOCATION} check)
  if("${check}" STREQUAL "")
    download_cpm()
  endif()
endif()

include(${CPM_DOWNLOAD_LOCATION})