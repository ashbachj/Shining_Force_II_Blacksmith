cmake_minimum_required (VERSION 2.6)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
add_subdirectory(${CMAKE_SOURCE_DIR}/src)

project (blacksmith)

add_executable(blacksmith ${CMAKE_SOURCE_DIR}/src/blacksmith.c ${CMAKE_SOURCE_DIR}/src/displayCharacterItems.c ${CMAKE_SOURCE_DIR}/src/freeBuffers.c ${CMAKE_SOURCE_DIR}/src/getIntFromUser.c ${CMAKE_SOURCE_DIR}/src/readItemList.c ${CMAKE_SOURCE_DIR}/src/readSaveState.c ${CMAKE_SOURCE_DIR}/src/transformItem.c)
