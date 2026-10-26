#include <cstdlib>
#include <iostream>
#include <string_view>

#include "fizzbuzz/fizzbuzz.hpp"

namespace {

int failures = 0;

void expect_eq(int value, std::string_view expected) {
    const auto actual = fizzbuzz::convert(value);
    if (actual != expected) {
        std::cerr << "FAIL: convert(" << value << ") == \"" << actual
                  << "\", expected \"" << expected << "\"\n";
        ++failures;
    }
}

}  // namespace

int main() {
    // Plain numbers
    expect_eq(1, "1");
    expect_eq(2, "2");
    expect_eq(98, "98");

    // Multiples of 3 only
    expect_eq(3, "Fizz");
    expect_eq(6, "Fizz");
    expect_eq(99, "Fizz");

    // Multiples of 5 only
    expect_eq(5, "Buzz");
    expect_eq(10, "Buzz");
    expect_eq(100, "Buzz");

    // Multiples of both 3 and 5
    expect_eq(15, "FizzBuzz");
    expect_eq(30, "FizzBuzz");
    expect_eq(90, "FizzBuzz");

    if (failures != 0) {
        std::cerr << failures << " test(s) failed\n";
        return EXIT_FAILURE;
    }
    std::cout << "All tests passed\n";
    return EXIT_SUCCESS;
}
