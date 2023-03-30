#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);

typedef struct C9
{
char god;
int (*a1)(va_list pf);
} B8 ;

int printc(va_list pf);
int printQ(va_list pf);
int print1(va_list pf);

#endif
