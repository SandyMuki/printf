#include <stdarg.h>
#include "main.h"

/**
 * _printf - produce output accoring to format
 * @format: input parmeter
 *
 * Return: count of input
 */
int _printf(const char *format, ...)
{

	int count = 0;
	char c, *s;
	va_list arg;

	if (format == NULL)
		return (-1);

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = (char) va_arg(arg, int);
					_putchar(c);
					count++;
					break;
				case 's':
					s = va_arg(arg, char *);
					count += _puts(s);
					break;
				case '%':
					_putchar(37);
					count++;
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(arg);
	return (count);
}
