cmake_minimum_required(VERSION 3.11...3.21)

project(TestTorchSocket)
# set(MODERN_CMAKE_BUILD_TESTING ON)

# include(CTest)


add_subdirectory(main)
add_subdirectory(socket)
add_subdirectory(third_party/fmt)