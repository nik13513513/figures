cmake_minimum_required(VERSION 3.7)

project(figures VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("third_party/gtest")
add_subdirectory("third_party/benchmark")

add_executable(figures src/bench.cpp src/figures.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE benchmark::benchmark)

