# Создаем исполняемый файл с тестами
add_executable(${MP2_TESTS}
    test_main.cpp
    test_stack.cpp
    test_queue.cpp
    test_bfs.cpp
)

# Подключаем папку include с нашими структурами
target_include_directories(${MP2_TESTS} PRIVATE 
    ${MP2_INCLUDE} 
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)
# Линкуем с библиотекой GTest
target_link_libraries(${MP2_TESTS} gtest)

# Добавляем тест в систему CTest, чтобы его можно было запускать через "ctest" или "make test"
add_test(NAME ${MP2_TESTS} COMMAND ${MP2_TESTS})