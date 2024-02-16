# S21 String Library

This is a C library project aimed at providing string manipulation functionalities.

## Installation

To install the library, follow these steps:

1. Clone the repository to your local machine:

```
git clone <repository-url>
```

2. Navigate to the project directory:

```
cd s21_string
```

3. Build the library using the provided Makefile:

```
make all
```

4. Optionally, you can run tests to ensure everything works correctly:

```
make test
```

5. You can also generate a coverage report using the following command:

```
make gcov_report
```

## Usage

To use the library in your C project, include the header file `s21_string.h`:

```c
#include "s21_string.h"
```

Then, link the library (`s21_string.a`) to your project during compilation.

## Features

- String manipulation functions such as copying, concatenation, and comparison.
- Memory management functions for strings.
- Test suite to ensure the correctness of the library functions.
- Coverage report generation to track code coverage.

## Contributing

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
