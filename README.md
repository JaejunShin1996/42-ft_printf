# ft_printf - Custom Implementation of printf()

## Project Overview

**ft_printf** is a project aimed at replicating the functionality of the standard `printf()` function in C. The project introduces the concept of variadic functions and covers essential string and data formatting operations. By completing this project, I gained a deeper understanding of how low-level output functions work and how to handle multiple argument types effectively.

The resulting `ft_printf()` function mimics the behavior of the original `printf()` from the C standard library, with support for a wide range of format specifiers and a flexible argument-handling mechanism.

---

## Key Features

- **Function Prototype**: `int ft_printf(const char *, ...);`
- **Supported Conversions**:
  - `%c` - Print a single character.
  - `%s` - Print a string.
  - `%p` - Print a pointer in hexadecimal format.
  - `%d` / `%i` - Print a decimal (base 10) integer.
  - `%u` - Print an unsigned decimal (base 10) integer.
  - `%x` - Print a number in hexadecimal (base 16), lowercase.
  - `%X` - Print a number in hexadecimal (base 16), uppercase.
  - `%%` - Print a literal percent sign.

---

## Skills Demonstrated

- **Variadic Functions**: Learned how to use `va_start`, `va_arg`, and `va_end` to handle variable numbers of arguments passed to a function.
- **Memory Management**: Ensured that dynamically allocated memory was properly freed, avoiding memory leaks.
- **Data Formatting**: Implemented various format specifiers for handling characters, strings, integers, and pointers.
- **Custom Output Handling**: Utilized `write()` for outputting formatted data, ensuring compatibility with standard output functions.

---

## Conclusion

The **ft_printf** project provided me with valuable experience in handling variable arguments, formatting complex data types, and managing memory in C. This function can now be integrated into future C projects, serving as a powerful tool for formatted output, much like the original `printf()`.

