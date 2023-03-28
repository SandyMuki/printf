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
					count += _puts(s);
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				case 'd':
				case 'i':
					count += print_int(va_arg(arg, int));
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
	return (count - 1);
}
/**
 * print_int - print integer to stdout and count
 * @n: integer to print
 *
 * Return: integer count
 */

int print_int(int n)
{
	int counter = 0;
	int rev = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		counter += 1;
	}

	while (n > 0)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}

	while (rev > 0)
	{
		_putchar(rev % 10 + '0');
		rev /= 10;
		counter += 1;
	}
	return (counter);
}
/**
 * _puts - prints characters of a string
 * @s: string to print
 *
 * Return: count of string
 */
int _puts(char *s)
{
	int counter = 0;

	while (*s++)
	{
		_putchar(*(s - 1));
		counter++;
	}
	return (counter);
}
