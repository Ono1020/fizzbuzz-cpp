cmake_minimum_required(VERSION 3.25)
project(fizzbuzz-cpp VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

# Library target holding the FizzBuzz logic, so both the
# application and the tests can use it.
add_library(fizzbuzz INTERFACE)
target_include_directories(fizzbuzz INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(fizzbuzz INTERFACE cxx_std_20)

add_executable(fizzbuzz-app src/main.cpp)
target_link_libraries(fizzbuzz-app PRIVATE fizzbuzz)
set_target_properties(fizzbuzz-app PROPERTIES OUTPUT_NAME fizzbuzz)

if(MSVC)
    target_compile_options(fizzbuzz-app PRIVATE /W4)
else()
    target_compile_options(fizzbuzz-app PRIVATE -Wall -Wextra -Wpedantic)
endif()

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
