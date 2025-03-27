#include "main.h"
/**
 * handle_octal - Handles the %o format specifier
 * @args: The list of arguments
 *
 * Return: Number of characters printed
 */
int handle_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_unsigned_base(num, 8, 0));
}
/**
 * handle_hex_lower - Handles the %x format specifier (lowercase hex)
 * @args: The list of arguments
 *
 * Return: Number of characters printed
 */
int handle_hex_lower(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_unsigned_base(num, 16, 0));
}
/**
 * handle_hex_upper - Handles the %X format specifier (uppercase hex)
 * @args: The list of arguments
 *
 * Return: Number of characters printed
 */
int handle_hex_upper(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_unsigned_base(num, 16, 1));
}
/**
 * handle_binary - Handles the %b format specifier (binary)
 * @args: The list of arguments
 *
 * Return: Number of characters printed
 */
int handle_binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_binary(num));
}
