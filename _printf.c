#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: Number of characters printed.
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
	{
