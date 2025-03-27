#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct specifier_handler - Maps a format specifier to its handler
 * @specifier: The format character (e.g. 'c', 's', 'd')
 * @handler: Pointer to the handler function
 */
typedef struct specifier_handler
{
	char specifier;
	int (*handler)(va_list);
} specifier_handler_t;

/* Core functions */
int _printf(const char *format, ...);
int call_handler(char specifier, va_list args);

/* Handler functions */
int handle_char(va_list args);
int handle_string(va_list args);
int handle_percent(va_list args);
int handle_int(va_list args);
int handle_unsigned(va_list args);
int handle_binary(va_list args);
int handle_octal(va_list args);
int handle_hex_lower(va_list args);
int handle_hex_upper(va_list args);

/* Helper functions*/
int print_number(int n);
int print_binary(unsigned int num);
int print_unsigned_base(unsigned int num, int base, int uppercase);

#endif
