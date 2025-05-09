cmake_minimum_required(VERSION 3.10)

project(simple_cpp_database VERSION 1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(simple_cpp_database src/simple_cpp_app.cpp)

target_include_directories(simple_cpp_database PUBLIC
                            "/usr/include/mysql")
target_link_libraries(simple_cpp_database PUBLIC
                            "soci_core"
                            "soci_mysql"
                            "dl"
                            "mysqlclient"
                      )
