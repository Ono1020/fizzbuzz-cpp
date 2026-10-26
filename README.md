# fizzbuzz-cpp

A minimal FizzBuzz implementation in modern C++ (C++20).

Reads a single integer `N` from standard input and prints the FizzBuzz
sequence from 1 to `N`, one value per line:

- multiples of 3 → `Fizz`
- multiples of 5 → `Buzz`
- multiples of both → `FizzBuzz`
- otherwise → the number itself

## Requirements

- A C++20 compiler (GCC 13, Clang 16, or MSVC 2022 or later)
- CMake 3.25 or later

## Build

```sh
cmake --preset release
cmake --build --preset release
```

Or without presets:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Usage

```sh
echo 15 | ./build/fizzbuzz
```

Output:

```text
1
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
FizzBuzz
```

## Test

```sh
ctest --preset release
```

This runs:

- `fizzbuzz.unit` — unit tests for the conversion logic
  (`tests/test_fizzbuzz.cpp`)
- `fizzbuzz.cli` — end-to-end test that feeds `15` to the binary and
  checks the full output

## Layout

```text
.
├── include/fizzbuzz/fizzbuzz.hpp  # FizzBuzz conversion logic (header-only)
├── src/main.cpp                   # Entry point: reads std::cin, prints the sequence
├── tests/                         # Unit and CLI tests (CTest)
├── CMakeLists.txt
└── CMakePresets.json
```

## License

MIT — see [LICENSE](LICENSE).
