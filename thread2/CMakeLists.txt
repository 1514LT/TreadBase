project(thread2)
set(CMAKE_CXX_STANDARD 11)  
cmake_minimum_required(VERSION 3.21)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cpp ThreadBase.cpp)

target_link_libraries(${PROJECT_NAME} pthread)