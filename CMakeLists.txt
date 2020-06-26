cmake_minimum_required(VERSION 3.16)
project(peko CXX)

message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Add source to this project's executable.
add_library(peko SHARED
	src/peko.cpp
	src/hooks/hooks.cpp
	src/interfaces/interfaces.cpp
	src/trigger/trigger.cpp
	src/glow/glow.cpp
	src/bhop/bhop.cpp
	src/common.cpp)

# Get rid of the `lib` prefix.
set_target_properties(peko PROPERTIES PREFIX "")

target_include_directories(peko PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${CMAKE_CURRENT_SOURCE_DIR}/include)

# TODO: This causes a bunch of warnings to appear.
target_link_libraries(peko PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/lib/libMinHook-x86-v141-mtd.lib)

target_compile_features(peko PRIVATE cxx_std_17)
