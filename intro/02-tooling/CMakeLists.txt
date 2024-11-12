add_executable(02-hello hello.cpp)
add_executable(02-extremelyBasic extremelyBasic.cpp)

if(WIN32)
  add_custom_target(
        02-extremelyBasic-Test
        COMMAND 02-extremelyBasic < ${CMAKE_CURRENT_SOURCE_DIR}/extremelyBasic.test.01.in > yourOutput.out
        COMMAND fc yourOutput.out ${CMAKE_CURRENT_SOURCE_DIR}/extremelyBasic.test.01.out
        DEPENDS 02-extremelyBasic
  )
else()
  add_custom_target(
          02-extremelyBasic-Test
          COMMAND 02-extremelyBasic < ${CMAKE_CURRENT_SOURCE_DIR}/extremelyBasic.test.01.in > yourOutput.out
          COMMAND diff yourOutput.out ${CMAKE_CURRENT_SOURCE_DIR}/extremelyBasic.test.01.out
          DEPENDS 02-extremelyBasic
  )
endif()