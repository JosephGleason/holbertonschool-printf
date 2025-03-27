#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}
			count += call_handler(format[i], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}

	va_end(args);
	return (count);
}
