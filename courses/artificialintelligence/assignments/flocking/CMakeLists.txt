add_executable(flocking flocking.cpp)

file(GLOB TEST_INPUT_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.in)
file(GLOB TEST_OUTPUT_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.out)

add_custom_test(flocking-test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/flocking "${TEST_INPUT_FILES}" "${TEST_OUTPUT_FILES}")

