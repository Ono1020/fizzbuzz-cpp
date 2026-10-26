#pragma once

#include <string>

namespace fizzbuzz {

// Returns "Fizz" for multiples of 3, "Buzz" for multiples of 5,
// "FizzBuzz" for multiples of both, and the number itself otherwise.
[[nodiscard]] inline std::string convert(int value) {
    if (value % 15 == 0) {
        return "FizzBuzz";
    }
    if (value % 3 == 0) {
        return "Fizz";
    }
    if (value % 5 == 0) {
        return "Buzz";
    }
    return std::to_string(value);
}

}  // namespace fizzbuzz
