cmake_minimum_required(VERSION 3.9)
project(GOOD LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
file( GLOB_RECURSE  impl_c "impl/*.c")
file(GLOB_RECURSE impl_cpp "impl/*.cpp")

file( GLOB_RECURSE  alloc_c "alloc/*.c")
file(GLOB_RECURSE src_c "src/*.c")
add_library(malloc SHARED ${alloc_c})

target_include_directories(malloc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE src_cpp  "src/*.cpp")
add_library(lib_impl SHARED ${impl_c} ${impl_cpp})
target_link_libraries(lib_impl PUBLIC malloc)
target_include_directories(lib_impl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(exe ${src_c} ${src_cpp})

target_include_directories(exe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(exe PUBLIC lib_impl)
