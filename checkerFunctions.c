#include "main.h"
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
/**
 * printC - prints a character.
 * @pf: is the va_list of format.
 * Return: 1 (len of the character).
 */
int printC(va_list pf)
{
	char a;

	a = va_arg(pf, int);
	write(1, &a, 1);
	return (1);
}

/**
 * printS - prints a string.
 * @pf: is the va_list of format.
 * Return: numbers (the len of the string).
 */
int printS(va_list pf)
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
 * printM - prints a %.
 * @pf: is the va_list of format.
 * Return: 1 (len of %).
 */
int printM(__attribute__((unused)) va_list pf)
{
	char m = '%';

	write(1, &m, 1);
	return (1);
}

/**
 * printInt - prints a int.
 * @pf: is the va_list of format.
 * Return: size (len of int).
 */
int printInt(va_list pf)
{
int n = va_arg(pf, int);
        int d, size;
        unsigned int num;

        d = 1;
        size = 0;
        num = n;
        if (n < 0)
        {
                putchar('-');
                size++;
                num = -n;
        }

        while (num / d > 9)
                d *= 10;
        while (d != 0)
        {
                putchar('0' + num / d);
                size++;
                num %= d;
                d /= 10;
        }
        return (size);
}
