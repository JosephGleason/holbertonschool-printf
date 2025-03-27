#include "main.h"

/**
 * print_number - Prints a signed integer
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */
int print_number(int n)
{
	char buffer[12];
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
 * print_binary - Prints binary representation of unsigned int
 * @num: Number to convert
 *
 * Return: Number of characters printed
 */
int print_binary(unsigned int num)
{
	char buffer[32];
	int i = 0, j, count = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (num > 0)
	{
		buffer[i++] = (num % 2) + '0';
		num = num / 2;
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}

	return (count);
}

/**
 * print_unsigned_base - Converts and prints an unsigned int in any base
 * @num: The number to convert and print
 * @base: The base to convert to (e.g. 10, 8, 16)
 * @uppercase: 1 = uppercase hex, 0 = lowercase
 *
 * Return: Number of characters printed
 */
int print_unsigned_base(unsigned int num, int base, int uppercase)
{
	char *lookup;
	char buffer[32];
	int i = 0, j, count = 0;

	if (uppercase)
		lookup = "0123456789ABCDEF";
	else
		lookup = "0123456789abcdef";

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (num > 0)
	{
		buffer[i++] = lookup[num % base];
		num = num / base;
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}

	return (count);
}
