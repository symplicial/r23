target_sources(r23 PRIVATE

)
target_include_directories(r23 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(WIN32)
  add_subdirectory(windows)
endif(WIN32)
