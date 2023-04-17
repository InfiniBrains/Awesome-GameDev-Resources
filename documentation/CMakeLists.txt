# cmake_minimum_required(VERSION 3.14...3.22)
#
# project(ConcurrencyDocs)

# ---- Dependencies ----

include(../cmake/get_cpm.cmake)

CPMAddPackage("gh:mosra/m.css#0da03060e30a23c0e9e54b0e25b71e9d2733d616")
# CPMAddPackage(NAME Concurrency SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

find_package(Doxygen)
if(NOT DOXYGEN_FOUND)
  message(FATAL_ERROR "Doxygen need to be installed to generate the doxygen documentation")
endif()

# ---- Doxygen variables ----

# set Doxyfile variables
set(DOXYGEN_PROJECT_NAME "Awesome GameDev Resources")
#set(DOXYGEN_PROJECT_VERSION ${Concurrency_VERSION})
set(DOXYGEN_PROJECT_ROOT "${CMAKE_CURRENT_LIST_DIR}/..")
set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/doxygen")

configure_file(${CMAKE_CURRENT_LIST_DIR}/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

add_custom_target(
  GenerateDocs
#  ${CMAKE_COMMAND} -E make_directory "${DOXYGEN_OUTPUT_DIRECTORY}"
#  COMMAND "${m.css_SOURCE_DIR}/documentation/doxygen.py" "${CMAKE_CURRENT_BINARY_DIR}/conf.py"
#  COMMAND doxygen ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
#  COMMAND moxygen --anchors --groups --output ${CMAKE_CURRENT_SOURCE_DIR}/api/api-%s.md ${DOXYGEN_OUTPUT_DIRECTORY}/xml
  COMMAND mkdocs build
  COMMAND echo "Docs written to: ${CMAKE_CURRENT_SOURCE_DIR}/../site"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../"
#  WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
)
