#include "main.h"
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * printI - prints a int.
 * @pf: is the va_list of format.
 * Return: 1 (len of int).
 */
int printInt(va_list pf)
{
	int N = va_arg(pf, int);
	int n = 1, size = 0;
	unsigned int num = N;
	int plus;

	if (n < 0)
	{
		write(1, &"-", 1);
		size++;
	}
	while (num / n > 9)
		n *= 10;
	while (n != 0)
	{
		plus = 0 + num / n;
		write(1, &plus, 1);
		size++;
		num %= n;
		n /= 10;
	}
	return (size);
}

/**
 * checker - checks what is the character and prints it
 * @pf: is the va_list of format
 * @C: is format[i + 1].
 * Return: the len of the thing printed
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

	int j = 0;
	int h = 0;

	while (D10[j].god)
	{
		if (*D10[j].god == C)
		{
			h += D10[j].a1(pf);
			break;
		}
		j++;
	}
	if (!D10[j].god)
	{
		h += D10[2].a1(pf);
		write(1, &C, 1);
		h++;
	}
	return (h);
}

/**
 * _printf - is our version of printf.
 * @format: the thing to print.
 * Return: h (len of the word printed).
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int h = 0;
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
			h += checker(pf, format[i + 1]);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			h++;
		}
		i++;
	}
	va_end(pf);
	return (h);
}
