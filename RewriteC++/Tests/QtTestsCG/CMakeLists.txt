cmake_minimum_required(VERSION 3.5)

project(TriangleTests LANGUAGES CXX)


find_package(Qt5Test REQUIRED)
find_package(Qt5Gui REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(TriangleTests tst_triangletests.cpp)
add_test(NAME TriangleTests COMMAND TriangleTests)

target_link_libraries(TriangleTests PRIVATE Qt5::Gui Qt5::Test)

