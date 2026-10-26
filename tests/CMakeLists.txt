add_executable(test_fizzbuzz test_fizzbuzz.cpp)
target_link_libraries(test_fizzbuzz PRIVATE fizzbuzz)

if(MSVC)
    target_compile_options(test_fizzbuzz PRIVATE /W4)
else()
    target_compile_options(test_fizzbuzz PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_test(NAME fizzbuzz.unit COMMAND test_fizzbuzz)

# End-to-end check: feeding "15" to the binary must produce
# the classic 1..15 FizzBuzz sequence.
add_test(NAME fizzbuzz.cli
    COMMAND ${CMAKE_COMMAND}
        -DPROGRAM=$<TARGET_FILE:fizzbuzz-app>
        -P ${CMAKE_CURRENT_SOURCE_DIR}/run_cli_test.cmake
)
