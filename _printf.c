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
				case 'd':
				case 'i':
					count += print_int((long int)va_arg(arg, int));
					break;
				default:
					count += _putchar('%');
					if (*format == '\0')
						return (-1);
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
