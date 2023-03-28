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
					count += _putchar((unsigned char)va_arg(arg, int));
					break;
				case 's':
					count += _puts(va_arg(arg, char *));
					break;
				case '%':
					count += _putchar(37);
					break;

				default:
					count += _putchar('%');
					count += _putchar(*format);
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
