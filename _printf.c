#include "main.h"
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * printc - prints a character.
 * @pf: is the va_list of format.
 * Return: 1 (len of the character).
 */
int printc(va_list pf)
{
	char a;

	a = va_arg(pf, int);
	write(1, &a, 1);
	return (1);
}

/**
 * printQ - prints a string.
 * @pf: is the va_list of format.
 * Return: numbers (the len of the string).
 */
int printQ(va_list pf)
{
	char *b;
	int numbers = 0;

	b = va_arg(pf, char *);
	if (b == NULL)
		b = "(null)";
	while (b[numbers] != '\0')
	{
		write(1, &b[numbers], 1);
		numbers++;
	}
	return (numbers);
}

/**
 * print1 - prints a %.
 * @pf: is the va_list of format.
 * Return: 1 (len of %).
 */
int print1(__attribute__((unused)) va_list pf)
{
	char m = '%';

	write(1, &m, 1);
	return (1);
}

/**
 * printWord - prints the word.
 * @w: the word to prints.
 * Return: 1.
 */
int printWord(char w)
{
	write(1, &w, 1);
	return (1);
}

/**
 * _printf - is our version of printf.
 * @format: the thing to print.
 * Return: h (len of the word printed).
 */
int _printf(const char *format, ...)
{
	B8 D10[] = {
		{'c', printc},
		{'s', printQ},
		{'%', print1},
		{'\0', NULL},
	};
	int i, j;
	int h = 0;
	va_list pf;

	if (!format)
		return (-1);
	va_start(pf, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (-1);
			j = 0;
			while (D10[j].god)
			{
				if (D10[j].god == format[i + 1])
				{
					h += D10[j].a1(pf);
					i++;
					break;
				}
				j++;
			}
			if (!D10[j].god)
				h += D10[2].a1(pf);
		}
		else
			h += printWord(format[i]);
		i++;
	}
	va_end(pf);
	return (h);
}
