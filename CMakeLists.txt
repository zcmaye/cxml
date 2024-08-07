﻿cmake_minimum_required(VERSION 3.13)

project(cxml CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


file(GLOB CXMAL_HEADERS "src/*.hpp")
file(GLOB CXMAL_SOURCES "src/*.cc")

add_library(cxml ${CXMAL_SOURCES})

target_include_directories(cxml
  PUBLIC
    $<INSTALL_INTERFACE:include>    
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

install(FILES ${CXMAL_HEADERS} DESTINATION include/cxml)
install(TARGETS cxml RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)

if(BUILD_TESTS)
  file(GLOB TEST_SOURCE "test/*.cpp")
  add_executable(test ${TEST_SOURCE})
  target_link_libraries(test cxml)
endif()
