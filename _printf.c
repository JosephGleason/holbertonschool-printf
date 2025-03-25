#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * print_number - Prints an integer to stdout
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
	char buffer[12]; /* enough to hold -2147483648\0 */
	int i = 0, j, count = 0;
	unsigned int num;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num = num / 10;
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}

	return (count);
}

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
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int num = va_arg(args, int);
				word_count += print_number(num);
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
