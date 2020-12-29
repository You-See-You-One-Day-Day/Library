cmake_minimum_required(VERSION 3.17)
project(Library)

set(CMAKE_CXX_STANDARD 14)

add_executable(Students CommonUser.cpp)
add_executable(User User.cpp)
add_executable(Administrator Administrator.cpp)
add_executable(Library Library.cpp)