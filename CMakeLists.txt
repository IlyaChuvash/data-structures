cmake_minimum_required(VERSION 3.16)
project(data_structures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем Google Test
add_subdirectory(googletest)

add_executable(Test_main 
    Test/Test_main.cpp 
    Test/Test_Queue.cpp 
    Test/Test_stack.cpp
)

# Включаем ВСЕ необходимые директории
target_include_directories(Test_main PRIVATE 
    ${CMAKE_SOURCE_DIR}/Structures
    ${CMAKE_SOURCE_DIR}/googletest/googletest/include
    ${CMAKE_SOURCE_DIR}/googletest/googlemock/include
)

# Связываем с gtest
target_link_libraries(Test_main gtest gtest_main)