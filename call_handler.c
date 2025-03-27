#include "main.h"

/**
 * call_handler - Finds the correct function and calls it
 * @specifier: Format character (e.g. 'd', 's')
 * @args: Argument list
 *
 * Return: Number of characters printed
 */
int call_handler(char specifier, va_list args)
{
	int i;

	specifier_handler_t handlers[] = {
		{'c', handle_char},
		{'s', handle_string},
		{'d', handle_int},
		{'i', handle_int},
		{'u', handle_unsigned},
		{'b', handle_binary},
		{'o', handle_octal},
		{'x', handle_hex_lower},
		{'X', handle_hex_upper},
		{'%', handle_percent},
		{'\0', NULL}
	};

	for (i = 0; handlers[i].specifier != '\0'; i++)
	{
		if (handlers[i].specifier == specifier)
			return (handlers[i].handler(args));
	}

	write(1, "%", 1);
	write(1, &specifier, 1);
	return (2);
}
