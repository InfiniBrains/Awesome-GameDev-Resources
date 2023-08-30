# set the minimum cmake version to generate projects.
cmake_minimum_required(VERSION 3.14)

project(
        AwesomeCppCourse
        LANGUAGES CXX
        VERSION 0.0.1 # todo: get this version from git tag
)

# set output folder
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

# ---- Add dependencies via CPM ----
# see https://github.com/TheLartians/CPM.cmake for more info
include(cmake/get_cpm.cmake)

# include sanitizers
include(cmake/tools.cmake)

# check if we are target compiling to web
if(EMSCRIPTEN)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Oz -s WASM=2")
endif()

CPMAddPackage("gh:onqtam/doctest@2.4.8")

# options to what include and use
OPTION(ENABLE_INTRO "ENABLE_INTRO" ON)
IF(ENABLE_INTRO)
  set(CMAKE_CXX_STANDARD 20)
  add_subdirectory(courses/intro)
endif()

# options to what include and use
OPTION(ENABLE_ADVANCED_CPP "ENABLE_ADVANCED_CPP" ON)
IF(ENABLE_ADVANCED_CPP)
  set(CMAKE_CXX_STANDARD 20)
  add_subdirectory(courses/advanced)
endif()

# todo: do the same for the other topics
OPTION(ENABLE_DOCUMENTATION "ENABLE_DOCUMENTATION" OFF)
IF(ENABLE_DOCUMENTATION)
  add_subdirectory(documentation)
ENDIF()

CPMAddPackage("gh:TheLartians/Format.cmake@1.7.3")

add_subdirectory(courses/artificialintelligence)