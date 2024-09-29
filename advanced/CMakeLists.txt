subdirlist(advcpp_chapters ${CMAKE_CURRENT_SOURCE_DIR})

foreach(subdir ${advcpp_chapters})
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/CMakeLists.txt")
        add_subdirectory(${subdir})
    endif()
endforeach()