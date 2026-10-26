# Runs the fizzbuzz binary with input "15" and verifies its output.
execute_process(
    COMMAND "${PROGRAM}"
    INPUT_FILE "${CMAKE_CURRENT_LIST_DIR}/input_15.txt"
    OUTPUT_VARIABLE output
    RESULT_VARIABLE result
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

if(NOT result EQUAL 0)
    message(FATAL_ERROR "fizzbuzz exited with code ${result}")
endif()

set(expected "1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz")

if(NOT output STREQUAL expected)
    message(FATAL_ERROR "Unexpected output:\n${output}\nExpected:\n${expected}")
endif()

message(STATUS "CLI test passed")
