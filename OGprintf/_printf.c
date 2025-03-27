#include "main.h"
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


	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			if (format[i] == '%')
			{
				write(1, "%", 1);

				word_count += 1;
			}

			else if (format[i] == 'c')
			{
				/* Retrieve the next arg, which is promoted to int, then cast to char */
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
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int num = va_arg(args, int);

				word_count += print_number(num);
			}
			else if (format[i] == 'b')
			{
				unsigned int num = va_arg(args, unsigned int);

				word_count += print_binary(num);
			}

			else if (format[i] == 'u')
			{
				unsigned int num = va_arg(args, unsigned int);

				word_count += print_unsigned_base(num, 10, 0);
			}
			else if (format[i] == 'o')
			{
				unsigned int num = va_arg(args, unsigned int);

				word_count += print_unsigned_base(num, 8, 0);
			}
			else if (format[i] == 'x')
			{
				unsigned int num = va_arg(args, unsigned int);

				word_count += print_unsigned_base(num, 16, 0);
			}
			else if (format[i] == 'X')
			{
				unsigned int num = va_arg(args, unsigned int);

				word_count += print_unsigned_base(num, 16, 1);
			}
			else
			{
				write(1, &format[i - 1], 1);
				write(1, &format[i], 1);
				word_count += 2;
			}
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			word_count += 1;
			i++;
		}
	}
	va_end(args);
	return (word_count);

}
