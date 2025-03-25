#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	int word_count = 0;
	int i = 0;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}


	va_start (args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				write(1, "%", 1);

				word_count += 1;
			}

			else if (format[i] == 'c')
			{
				/* Retrieve the next argument, which is promoted to int, then cast to char */
				char ch = (char)va_arg(args, int);

				/* Write the character to stdout */
				write(1, &ch, 1);

				/* Increment your character counter by 1 */
				word_count += 1;

			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				int j = 0;

				if (str == NULL)
				{
					str = "(null)";
				}


				while (str[j] != '\0')
				{
					write(1, &str[j], 1);
					word_count += 1;
					j++;
				}

			}
		}
		else
		{
			write(1, &format[i], 1);
			word_count++;

		}
		i++;

	}
	va_end(args);
	return (word_count);
}
