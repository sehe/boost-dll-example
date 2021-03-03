project(stackoverflow)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

FIND_PACKAGE(Boost 1.61.0 REQUIRED COMPONENTS filesystem)
LINK_LIBRARIES(Boost::filesystem dl)

ADD_LIBRARY(my_plugin_sum SHARED plugin_impl.cpp)
ADD_EXECUTABLE(sotest test.cpp)
