#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int print_binary(unsigned int num);
int print_unsigned_base(unsigned int num, int base, int uppercase);
int print_number(int n);

#endif
