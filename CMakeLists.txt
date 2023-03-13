cmake_minimum_required(VERSION 3.3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

project(r23)

if(WIN32)
  add_executable(r23 WIN32)
  target_link_libraries(r23 PRIVATE user32)
endif(WIN32)

add_subdirectory(src)

find_package(Vulkan REQUIRED)
target_link_libraries(r23 PRIVATE Vulkan::Vulkan)
