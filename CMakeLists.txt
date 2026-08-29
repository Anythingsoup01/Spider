cmake_minimum_required(VERSION 4.4.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(spider-wks LANGUAGES CXX)
add_subdirectory(Spider)

add_subdirectory(test)

