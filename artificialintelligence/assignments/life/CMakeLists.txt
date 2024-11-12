add_executable(ai-life life.cpp)

file(GLOB TEST_INPUT_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.in)
file(GLOB TEST_OUTPUT_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.out)

add_custom_test(ai-life-test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ai-life "${TEST_INPUT_FILES}" "${TEST_OUTPUT_FILES}")

