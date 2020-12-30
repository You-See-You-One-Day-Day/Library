cmake_minimum_required(VERSION 3.17)
project(Library)

set(CMAKE_CXX_STANDARD 20)

add_executable(CommonUser CommonUser.cpp)
add_executable(User User.cpp)
add_executable(Administrator Administrator.cpp)
add_executable(Library Library.cpp)
add_executable(main main.cpp)