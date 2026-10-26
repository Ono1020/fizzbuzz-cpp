#include <iostream>

#include "fizzbuzz/fizzbuzz.hpp"

int main() {
    int n = 0;
    if (!(std::cin >> n)) {
        std::cerr << "error: an integer input is required\n";
        return 1;
    }
    if (n < 1) {
        std::cerr << "error: input must be a positive integer\n";
        return 1;
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << fizzbuzz::convert(i) << '\n';
    }
    return 0;
}
