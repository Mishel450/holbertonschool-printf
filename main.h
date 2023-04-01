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
char *god;
int (*a1)(va_list pf);
} B8;
int printC(va_list pf);
int printS(va_list pf);
int printM(va_list pf);
int printInt(va_list pf);
int checker(va_list pf, char C);
#endif
