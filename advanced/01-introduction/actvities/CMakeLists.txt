file(GLOB adv_intro_src CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

enable_testing()

add_executable(adv-01-intro ${adv_intro_src})
include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
target_include_directories(adv-01-intro PUBLIC ${DOCTEST_INCLUDE_DIR})
target_link_libraries(adv-01-intro doctest::doctest)
doctest_discover_tests(adv-01-intro)

if(ENABLE_TEST_COVERAGE)
    target_compile_options(adv-01-intro PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
    target_link_options(adv-01-intro PUBLIC -fprofile-arcs -ftest-coverage)
endif()