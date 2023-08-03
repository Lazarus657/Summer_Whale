cmake_minimum_required(VERSION 3.24)
project(whale)

set(CMAKE_CXX_STANDARD 17)

add_executable(whale main.cpp color.h color.cpp hint.h hint.cpp info.h info.cpp user.h config.h user.cpp good.h good.cpp order.h order.cpp menu.cpp menu.h interface.h mainInterface.cpp)
