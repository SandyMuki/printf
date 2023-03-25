#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _putchar - print a character
 *@c: charcter to print
 *
 * Return: count
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

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
					count += _puts(s, count);
					break;
			case '%':
					_putchar('%');
					count++;
					break;
			case 'd':
			case 'i':
					count += print_int(va_arg(arg, int), count);
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
/**
 * print_int - print integer to stdout and count
 * @intv: integer to print
 * @count: integer digits
 *
 * Return: integer count
 */

int print_int(int intv, int count)
{
	if (intv < 0)
	{
		_putchar('-');
		count++;
		intv = -intv;
	}
	if (intv / 10)
	{
		count += _printf("%d", intv / 10);
	}
	_putchar(intv % 10 + '0');
	count++;
	return (count);
}
/**
 * _puts - prints characters of a string
 * @s: string to print
 * @count: count of string
 *
 * Return: count of string
 */
int _puts(char *s, int count)
{
	while (*s++)
	{
		_putchar(*(s - 1));
		count++;
	}
	return (count);
}
