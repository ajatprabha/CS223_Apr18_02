cmake_minimum_required(VERSION 3.9)
project(ClassroomBookingSystem)

set(CMAKE_CXX_STANDARD 11)

add_executable(ClassroomBookingSystem src/main.cpp src/init.cpp src/init.h src/base/models.cpp src/base/models.h src/admin/models.cpp src/admin/models.h src/users/models.cpp src/users/models.h)