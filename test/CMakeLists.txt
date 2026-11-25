add_executable(${MP2_TESTS}
    test_main.cpp
    test_stack.cpp
    test_queue.cpp
    test_bfs.cpp
)

target_include_directories(${MP2_TESTS} PRIVATE 
    ${MP2_INCLUDE} 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)
target_link_libraries(${MP2_TESTS} gtest)

add_test(NAME ${MP2_TESTS} COMMAND ${MP2_TESTS})