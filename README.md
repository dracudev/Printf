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

**`[Not implemented]`**

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

1. **Undefined Behavior**:
   - If the format string specifies a format that does not match the type of subsequent arguments (e.g., using `%d` but passing a floating-point number), the behavior of `printf` is undefined. This can result in unexpected output or crashes.

2. **No Return Value for Errors**:
   - `printf` itself does not return an error code to indicate formatting errors. It typically returns the number of characters printed (excluding the null terminator), or a negative value if an error occurs during output.
   - When a char pointer (char *) is NULL and is used with the `%s` specifier, printf typically prints `(null)`.
   - When a pointer (for example, void *) is NULL and is used with the `%p` specifier, printf typically prints `(nil)`.

3. **Prevention and Debugging**:
   - Developers can prevent errors by carefully matching format specifiers with the types of arguments.
   - Compiler warnings (e.g., `-Wall` in GCC) can help catch some format string errors at compile-time.
   - Debugging tools and techniques (e.g., runtime checks, logging) can assist in identifying format string issues during program execution.

<br>

# Custom Implementation

## Ft_printf.c

### [ft_check_conv](ft_printf.c)

The `ft_check_conv` function determines the appropriate action based on the format specifier character `c`. It uses the `va_list` to retrieve the corresponding argument and processes it accordingly, updating the total length of the output.

```c
static void	ft_check_conv(char c, va_list *args, int *len, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(*args, int), len);
	else if (c == 's')
		ft_putstr(va_arg(*args, char *), len);
	else if (c == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*args, int), len);
	else if (c == 'u')
		ft_unsigned_int(va_arg(*args, int), len);
	else if (c == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'x');
	else if (c == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), len, 'X');
	else if (c == '%')
		ft_putchar('%', len);
	else
		(*i)--;
}
```

**Parameters**:
- `char c`: The format specifier character that indicates the type of argument to process (e.g., 'c', 's', 'd').
- `va_list *args`: A pointer to the list of arguments provided to `ft_printf`.
- `int *len`: A pointer to the integer that tracks the total length of the formatted output.
- `int *i`: A pointer to the current index in the format string.

**Functionality**:
- For each format specifier, the corresponding function is called to handle the argument:
  - `'c'`: Calls `ft_putchar` to print a single character.
  - `'s'`: Calls `ft_putstr` to print a string.
  - `'p'`: Calls `ft_pointer` to print a pointer value.
  - `'d'` or `'i'`: Calls `ft_putnbr` to print a signed integer.
  - `'u'`: Calls `ft_unsigned_int` to print an unsigned integer.
  - `'x'`: Calls `ft_hexadecimal` to print an unsigned integer in lowercase hexadecimal.
  - `'X'`: Calls `ft_hexadecimal` to print an unsigned integer in uppercase hexadecimal.
  - `'%'`: Calls `ft_putchar` to print a literal '%' character.
- If an invalid specifier is encountered, it decrements the index `i` to correctly handle the next character in the format string.

<br>

### [ft_printf](ft_printf.c)

The `ft_printf` function formats and prints a series of characters and variables according to the format specifiers in the provided format string.

```c
int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_check_conv(str[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putchar((char)str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
```

**Parameters**:
- `char const *str`: The format string containing the text and format specifiers.
- `...`: A variable number of arguments corresponding to the format specifiers in the format string.

**Return Value**:
- `int`: The total length of the formatted output.

**Functionality**:
1. **Initialization**:
   - `va_list args`: A variable argument list to handle the additional arguments.
   - `int i = 0`: The current index in the format string.
   - `int len = 0`: The total length of the formatted output.

2. **Start Variable Argument Processing**:
   - `va_start(args, str)`: Initializes the `va_list` to retrieve the additional arguments.

3. **Format String Parsing**:
   - A `while` loop iterates through each character in the format string `str`.

4. **Format Specifier Handling**:
   - If the current character is `'%'`:
     - Increment the index `i` to check the next character.
     - Call `ft_check_conv` to process the format specifier and the corresponding argument.
     - Increment the index `i` again to move past the format specifier.
   - If the current character is not `'%'`:
     - Call `ft_putchar` to print the character.
     - Increment the index `i`.

5. **End Variable Argument Processing**:
   - `va_end(args)`: Cleans up the `va_list`.

6. **Return the Total Length**:
   - Return `len`, the total length of the formatted output.

<br>

## Ft_text.c

Specific functions to make the correct text conversions.

### [ft_putchar](ft_text.c)

The `ft_putchar` function is a helper function used to print a single character to the standard output and update the total length of the output.

```c
void	ft_putchar(char ch, int *len)
{
	write(1, &ch, 1);
	(*len)++;
}
```

**Parameters**:
- `char ch`: The character to be printed.
- `int *len`: A pointer to an integer that tracks the total length of the formatted output.

**Functionality**:
- Uses the `write` system call to print the character `ch` to the standard output (`file descriptor 1`).
- Increments the integer pointed to by `len` to account for the printed character.

<br>

### [ft_putstr](ft_text.c)

The `ft_putstr` function is a helper function used to print a string to the standard output and update the total length of the output.

```c
void	ft_putstr(char *args, int *len)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (args[i])
	{
		ft_putchar(args[i], len);
		i++;
	}
}
```

**Parameters**:
- `char *args`: The string to be printed.
- `int *len`: A pointer to an integer that tracks the total length of the formatted output.

**Functionality**:
- Checks if the string `args` is `NULL`.
  - If `args` is `NULL`, prints `(null)` to the standard output and increments `len` by 6.
- If `args` is not `NULL`, iterates through each character in the string:
  - Calls `ft_putchar` to print each character.
  - Increments `len` for each character printed.

<br>

## Ft_numbers.c

Specific functions to make the correct number conversions.
### [ft_putnbr](ft_numbers.c)

The `ft_putnbr` function is a helper function used to print an integer to the standard output and update the total length of the output.

```c
void	ft_putnbr(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-', len);
		ft_putnbr(nbr * -1, len);
	}
	else
	{
		if (nbr > 9)
			ft_putnbr(nbr / 10, len);
		ft_putchar((nbr % 10) + '0', len);
	}
}
```

**Parameters**:
- `int nbr`: The integer to be printed.
- `int *len`: A pointer to an integer that tracks the total length of the formatted output.

**Functionality**:
- Checks if `nbr` is equal to `-2147483648`.
  - If true, prints `"-2147483648"` to the standard output and increments `len` by 11.
- Checks if `nbr` is negative.
  - If negative, prints `'-'` character using `ft_putchar`, and recursively calls `ft_putnbr` with the absolute value of `nbr`.
- If `nbr` is positive:
  - Recursively divides `nbr` by 10 until it becomes less than 10.
  - Uses `ft_putchar` to print each digit by converting it to ASCII character using `nbr % 10 + '0'`.

<br>

### [ft_unsigned_int](ft_numbers.c)

The `ft_unsigned_int` function is a helper function used to print an unsigned integer to the standard output and update the total length of the output.

```c
void	ft_unsigned_int(unsigned int u, int *len)
{
	if (u > 9)
		ft_unsigned_int(u / 10, len);
	ft_putchar((u % 10) + '0', len);
}
```

**Parameters**:
- `unsigned int u`: The unsigned integer to be printed.
- `int *len`: A pointer to an integer that tracks the total length of the formatted output.

**Functionality**:
- Recursively divides `u` by 10 until it becomes less than 10 (`u > 9`).
- Uses `ft_putchar` to print each digit by converting it to ASCII character using `(u % 10) + '0'`.

<br>

### [ft_pointer](ft_numbers.c)

The `ft_pointer` function is a helper function used to print a pointer address in hexadecimal format to the standard output and update the total length of the output.

```c
void	ft_pointer(size_t ptr, int *len)
{
	char	str[25];
	int		i;
	char	*base;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	base = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	while (ptr != 0)
	{
		str[i] = base[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
}
```

**Parameters**:
- `size_t ptr`: The pointer address to be printed.
- `int *len`: A pointer to an integer that tracks the total length of the formatted output.

**Functionality**:
- Checks if `ptr` is `NULL` (zero).
  - If true, prints `"(nil)"` to the standard output and increments `len` by 5.
- Initializes a string `base` with hexadecimal digits (`"0123456789abcdef"`).
- Writes `"0x"` to the standard output to indicate the start of a hexadecimal address and increments `len` by 2.
- Converts `ptr` to hexadecimal representation by repeatedly dividing it by 16 and storing the remainder (`ptr % 16`) in `str`.
- Uses `ft_putchar` to print each hexadecimal digit stored in `str` in reverse order.

<br>

### [ft_hexadecimal](ft_numbers.c)

The `ft_hexadecimal` function is a helper function used to print an unsigned integer in hexadecimal format to the standard output and update the total length of the output.

```c
void	ft_hexadecimal(unsigned int x, int *len, char x_X)
{
	char	str[25];
	char	*base;
	int		i;

	if (x_X == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	while (x != 0)
	{
		str[i] = base[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i], len);
}
```

**Parameters**:
- `unsigned int x`: The unsigned integer to be printed in hexadecimal.
- `int *len`: A pointer to an integer that tracks the total length of the formatted output.
- `char x_X`: Determines whether to use lowercase (`'x'`) or uppercase (`'X'`) hexadecimal digits.

**Functionality**:
- Selects the base character set (`base`) based on the value of `x_X`:
  - If `x_X` is `'X'`, uses `"0123456789ABCDEF"` (uppercase).
  - If `x_X` is `'x'` or any other character, uses `"0123456789abcdef"` (lowercase).
- Handles the special case where `x` is `0` by printing `'0'` and returning early.
- Converts `x` to hexadecimal representation by repeatedly dividing it by 16 (`x % 16`) and storing the remainder in `str`.
- Uses `ft_putchar` to print each hexadecimal digit stored in `str` in reverse order.
