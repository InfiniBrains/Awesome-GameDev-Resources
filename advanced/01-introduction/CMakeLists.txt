subdirlist(activity_dir ${CMAKE_CURRENT_SOURCE_DIR})

foreach(subdir ${activity_dir})
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt")
        add_subdirectory(${subdir})
    endif()
endforeach()