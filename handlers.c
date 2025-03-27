#include "main.h"
/**
 * handle_char - Handles the %c format specifier
 * @args: The list of arguments
 *
 * Return: Number of characters printed
 */
int handle_char(va_list args)
{
	char c = (char)va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
/**
 * handle_string - Handles the %s format specifier
 * @args: The list of arguments
 *
 * Return: Number of characters printed
 */
int handle_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (str == NULL)
		str = "(null)";
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
/**
 * handle_percent - Handles the %% format specifier
 * @args: The list of arguments (unused)
 *
 * Return: Number of characters printed
 */
int handle_percent(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}
/**
 * handle_int - Handles the %d and %i format specifiers
 * @args: The list of arguments
 *
 * Return: Number of characters printed
 */
int handle_int(va_list args)
{
	int num = va_arg(args, int);

	return (print_number(num));
}
/**
 * handle_unsigned - Handles the %u format specifier
 * @args: The list of arguments
 *
 * Return: Number of characters printed
 */
int handle_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);

	return (print_unsigned_base(num, 10, 0));
}
