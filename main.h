#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

/**
 * struct C9 - the structure used for _printf.
 * @god: .
 * @a1: .
 *
 * Description: .
 */
typedef struct C9
{
int god;
int (*a1)(va_list pf);
} B8;
int printc(va_list pf);
int printQ(va_list pf);
int print1(va_list pf);
int printWord(char w);

#endif
