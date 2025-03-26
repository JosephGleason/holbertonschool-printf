#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_unsigned_base - converts unsigned int to any base
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */
int print_unsigned_base(unsigned int num, int base, int uppercase)
{
	char *lookup;
	char buffer[32];
	int i = 0, j, count = 0;
	int remainder;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	if (uppercase)
	{
		lookup = "0123456789ABCDEF";
	}
	else
	{
		lookup = "0123456789abcdef";
	}

	while (num > 0)
	{
		remainder = num % base;
		buffer[i] = lookup[remainder];
		i++;
		num = num / base;

	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}
	return (count);
}
