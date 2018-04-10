
cmake_minimum_required(VERSION 3.5)
project(modio_workshop_wrapper)
set(CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_STANDARD 11)

add_definitions(-DBUILDING_MODIO_WORKSHOP_WRAPPER_DLL)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(modio_workshop_wrapper SHARED ${SOURCES})

IF (APPLE)
  target_link_libraries(modio_workshop_wrapper ${CMAKE_SOURCE_DIR}/lib/osx32/libsteam_api.dylib ${CMAKE_SOURCE_DIR}/lib/osx32/libmodio.dylib )
ENDIF()

IF (MSVC)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_link_libraries(modio_workshop_wrapper ${CMAKE_SOURCE_DIR}/lib/win64/steam_api64.lib  ${CMAKE_SOURCE_DIR}/lib/win64/modio.lib )
  elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
    target_link_libraries(modio_workshop_wrapper ${CMAKE_SOURCE_DIR}/lib/win32/steam_api64.lib  ${CMAKE_SOURCE_DIR}/lib/win32/modio.lib )
  endif()
ENDIF()