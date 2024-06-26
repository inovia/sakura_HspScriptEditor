cmake_minimum_required(VERSION 3.6)
include(${CMAKE_SOURCE_DIR}/runtime.cmake)

project (sakura-unittest)

option(BUILD_GTEST "Build GoogleTest." ON)
option(BUILD_SHARED_LIBS "Build shared libraries (DLLs)." OFF)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)    # C++17...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...

# switch DLL or static libary by specifying by command line
set (LIB_TYPE STATIC)
if (BUILD_SHARED_LIBS)
  # User wants to build Dynamic Libraries, so change the LIB_TYPE variable to CMake keyword 'SHARED'
  set (LIB_TYPE SHARED)
endif (BUILD_SHARED_LIBS)

# set Target Directories
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if(BUILD_GTEST)
	add_subdirectory(googletest)
endif()
add_subdirectory(compiletests)
add_subdirectory(unittests)

# turn on solution folder
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# create solution folder
if(BUILD_GTEST)
	set_target_properties(gtest       PROPERTIES FOLDER GoogleTest)
	set_target_properties(gmock       PROPERTIES FOLDER GoogleTest)
endif()
set_target_properties(tests1      PROPERTIES FOLDER Tests)

# specify startup project
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT tests1)

# enable testing
enable_testing()

# add test
add_test(NAME unitTest1 COMMAND tests1)
