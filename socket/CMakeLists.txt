cmake_minimum_required(VERSION 3.8)

project(
  TestSocket
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include_directories(../third_party/fmt/include)

add_library(
  SocketLib
  error.h
  exception.h
  exception.cpp
  socket.h
  socket.cpp
  Store.hpp
  Store.cpp
  TCPStore.hpp
  TCPStore.cpp
  UnixSockUtils.hpp
  Utils.hpp)

add_executable(SocketServer socket_server.cpp)
add_executable(SocketWorker socket_worker.cpp)

# Make sure you link your targets with this command. It can also link libraries and
# even flags, so linking a target that does not exist will not give a configure-time error.
target_link_libraries(SocketServer PRIVATE SocketLib fmt::fmt)
target_link_libraries(SocketWorker PRIVATE SocketLib fmt::fmt)
