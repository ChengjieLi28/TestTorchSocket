cmake_minimum_required(VERSION 3.11...3.21)

project(TestTorchSocket)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(socket)
add_subdirectory(third_party/fmt)
add_subdirectory(third_party/pybind11)

pybind11_add_module(example_bind socket/BindTCPStore.cpp)
target_link_libraries(example_bind PRIVATE SocketLib fmt::fmt)
