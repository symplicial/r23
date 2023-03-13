target_sources(r23 PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
target_include_directories(r23 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(graphics)
add_subdirectory(misc)
add_subdirectory(platform)
