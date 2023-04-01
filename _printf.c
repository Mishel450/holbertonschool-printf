#include "main.h"
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
/**
 * checker - checks what is the character and prints it.
 * @pf: is the va_list of format
 * @C: is format[i + 1] and the character to check.
 * Return: the len of the character or string printed.
 */
int checker(va_list pf, char C)
{
	B8 D10[] = {
		{"c", printC},
		{"s", printS},
		{"%", printM},
		{"d", printInt},
		{"i", printInt},
		{'\0', NULL},
	};

	int i = 0;
	int size = 0;

	while (D10[i].c)
	{
		if (*D10[i].c == C)
		{
			size += D10[i].st(pf);
			break;
		}
		i++;
	}
	if (!D10[i].c)
	{
		size += D10[2].st(pf);
		write(1, &C, 1);
		size++;
	}
	return (size);
}

/**
 * _printf - is our version of printf.
 * @format: the characters to print.
 * Return: sizeAll (len of the word printed).
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int sizeAll = 0;
	va_list pf;

	if (!format)
		return (-1);
	va_start(pf, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			sizeAll += checker(pf, format[i + 1]);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			sizeAll++;
		}
		i++;
	}
	va_end(pf);
	return (sizeAll);
}
