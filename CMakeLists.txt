cmake_minimum_required(VERSION 3.9)
project(ClassroomBookingSystem)

set(CMAKE_CXX_STANDARD 11)

include_directories(code)

add_subdirectory(code)
add_subdirectory(lib)
add_subdirectory(tests)