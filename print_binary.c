#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_binary - Custom printf implementation to handle various format specifiers.
 * @format: The format string containing the characters & specifiers to print.
 *
 * Return: The total number of characters printed
 */
int print_binary(unsigned int num)
{
	char buffer[32];
	int i = 0, j, remainder;
	int count = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return(1);
	}

	while (num > 0)
	{
		remainder = num % 2;

		if (remainder == 1)
		{
			buffer[i] = '1';
		}
		else
		{
			buffer[i] = '0';
		}
		i++;
		num = num / 2;
	}
	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}
	return (count);
}
