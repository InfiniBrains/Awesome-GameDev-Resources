add_executable(ai-catchthecat simulator.cpp)

file(GLOB TEST_INPUT_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.in)
file(GLOB TEST_OUTPUT_FILES ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.out)

add_custom_test(ai-catchthecat-test ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ai-catchthecat "${TEST_INPUT_FILES}" "${TEST_OUTPUT_FILES}")