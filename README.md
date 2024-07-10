# Ft_Printf

Custom implementation of the standard `printf` function, capable of formatting and printing a variety of data types. This project is designed to handle the following conversion specifiers:

| Conversion | Short Description                                                                             |
|------------|-----------------------------------------------------------------------------------------------|
| %c         | Print a single character.                                                                     |
| %s         | Print a string of characters.                                                                 |
| %p         | The void * pointer argument is printed in hexadecimal.                                        |
| %d         | Print a decimal (base 10) number.                                                             |
| %i         | Print an integer in base 10.                                                                  |
| %u         | Print an unsigned decimal (base 10) number.                                                   |
| %x         | Print a number in hexadecimal (base 16), with lowercase.                                      |
| %X         | Print a number in hexadecimal (base 16), with uppercase.                                      |
| %%         | Print a percent sign.                                                                         |

The `ft_printf` project involves implementing variadic functions. This exercise is designed to deepen understanding of:

- Handling different data types and format specifiers.
- Managing variable argument lists using the `stdarg.h` library.
- Working with low-level input/output operations.
- Enhancing knowledge of memory management and pointer manipulation.

<br>

# Basic Functionality
The `printf` function in C and other programming languages is used primarily to format and output data to the standard output stream (usually the console). It accepts a format string followed by a variable number of arguments. The format string contains conversion specifiers that control how the subsequent arguments are formatted and displayed.

1. **Format String**: 
   - This is a string literal that can contain ordinary characters (which are copied directly to the output) and format specifiers (which are replaced by the formatted representation of corresponding arguments).

2. **Conversion Specifiers**: 
   - Begin with a `%` character followed by specific characters that determine the type and formatting of each argument. For example, `%d` for integers, `%f` for floating-point numbers, `%s` for strings, etc.

3. **Variable Number of Arguments**: 
   - `printf` can accept multiple arguments after the format string. The number and types of these arguments depend on the format specifiers in the format string.

4. **Output to Standard Output**: 
   - Once formatted, the resulting string is typically displayed on the standard output (console). It can also be redirected to files or other output streams using file redirection or similar mechanisms.

### Example:

```c
#include <stdio.h>

int main() {
    int num = 42;
    float pi = 3.14159;
    char name[] = "John Doe";

    // Example usage of printf
    printf("Integer: %d, Float: %f, String: %s\n", num, pi, name);

    return 0;
}
```

<br>

# Components of a Format Specifier

A format specifier can have several components, including:

1. **Flags**: Optional characters that modify the output format. Common flags include:
   - `-`: Left-justify the output within the given field width.
   - `+`: Always show the sign of a number.
   - `0`: Pad the field with zeros instead of spaces.
   - `#`: Use an alternate form (e.g., `0x` prefix for hexadecimals).
   - `.`: Precision after the decimal point
   - `_`: Adds a space before value

2. **Width**: An optional number specifying the minimum field width. If the converted value is shorter, it is padded with spaces (or zeros if the `0` flag is used).

3. **Precision**: An optional number following a `.` that specifies the number of digits to appear after the decimal point for floating-point numbers or the maximum number of characters to be printed from a string.

4. **Length Modifier**: Optional characters that modify the length of the data type. For example:
   - `h`: Short (e.g., `short int`).
   - `l`: Long (e.g., `long int`).
   - `ll`: Long long (e.g., `long long int`).

5. **Conversion Specifier**: The character that specifies the type of conversion to be applied (e.g., `d`, `f`, `s`, etc.).

### Example

For example, in the format specifier `%10.2f`:
- `%` indicates the start of the format specifier.
- `10` is the width, meaning the total field should be 10 characters wide.
- `.2` is the precision, indicating 2 digits should appear after the decimal point.
- `f` is the conversion specifier, indicating a floating-point number.

<br>

# Variable Arguments

The `printf` function in C and related languages supports a variable number of arguments after the format string. This feature allows it to handle different types and numbers of arguments based on the format specifiers provided in the format string.

1. **Format String**:
   - The format string in `printf` contains ordinary characters and conversion specifiers (e.g., `%d`, `%f`, `%s`) that specify how subsequent arguments should be formatted.

2. **Variable Arguments**:
   - After the format string, `printf` accepts a variable number of arguments corresponding to the conversion specifiers in the format string. These arguments can be of different types (integers, floats, strings, etc.) and their number can vary depending on the format specifiers.
  
**Variadic functions** in C are functions that can accept a variable number of arguments. This feature is particularly useful when the number of arguments needed by a function is not fixed.

To define a variadic function, you need to include the `stdarg.h` header and use the following macros:

1. `va_list`: A type to hold information about variable arguments.
2. `va_start`: Initializes a `va_list` variable to retrieve the additional arguments.
3. `va_arg`: Retrieves the next argument in the list.
4. `va_copy`: duplicates a `va_list` variable, allowing you to traverse the arguments multiple times if needed. 
5. `va_end`: Cleans up the `va_list` variable.

```c
#include <stdarg.h>

return_type function_name(int fixed_arg, ...);
```

<br>

# String Processing

The `printf` function in C and similar programming languages processes its format string to produce formatted output. String processing involves interpreting the format specifiers within the format string and replacing them with the corresponding values of subsequent arguments.

1. **Format String**:
   - The format string is a constant string literal that contains ordinary characters and format specifiers. It serves as a template for the final output.

2. **Format Specifiers**:
   - Format specifiers begin with a `%` character and are followed by optional flags, width, precision, length modifiers, and a conversion specifier (e.g., `%d`, `%f`, `%s`). These specifiers determine how the subsequent arguments are formatted and inserted into the output string.

3. **Processing Flow**:
    
    - `printf` reads the format string character by character.
    - When encountering a `%`, it identifies the beginning of a format specifier.
    - It parses the specifier to determine its components (flags, width, precision, length modifier, conversion specifier).
    - It then fetches the corresponding argument and formats it according to the specifier's rules.
    - The formatted result is concatenated to the final output string.
    
4. **Output**:
    
    - After processing the entire format string and replacing all specifiers with their corresponding values, `printf` outputs the final formatted string to the standard output (usually the console).

<br>

# Error Handling
1. **Format String Validity**:
   - The format string passed to `printf` must be well-formed with correct format specifiers. Incorrect usage of format specifiers or mismatched arguments can lead to undefined behavior or runtime errors.

2. **Undefined Behavior**:
   - If the format string specifies a format that does not match the type of subsequent arguments (e.g., using `%d` but passing a floating-point number), the behavior of `printf` is undefined. This can result in unexpected output or crashes.

3. **No Return Value for Errors**:
   - `printf` itself does not return an error code to indicate formatting errors. It typically returns the number of characters printed (excluding the null terminator), or a negative value if an error occurs during output.

4. **Common Issues**:
   - Forgetting to provide enough arguments for all format specifiers in the format string (`printf("Number: %d\n", 42);` expects an integer after `%d`).
   - Mixing up format specifiers (`printf("Float: %f\n", 42);` should use `%d` for integers).
   - Using incorrect format specifiers for the types of arguments (`printf("String: %s\n", 42);` attempts to print an integer as a string).

5. **Prevention and Debugging**:
   - Developers can prevent errors by carefully matching format specifiers with the types of arguments.
   - Compiler warnings (e.g., `-Wall` in GCC) can help catch some format string errors at compile-time.
   - Debugging tools and techniques (e.g., runtime checks, logging) can assist in identifying format string issues during program execution.

<br>

# Custom Implementation

[In process]
