#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - print a character
 *@: charcter to print
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printf(const char *format, ...)
{
	int count = 0;
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
				{
					char c = (char) va_arg(arg, int);

					_putchar(c);
					count++;
					break;
				}
			case 's':
				{
					char *s = va_arg(arg, char *);

					while (*s++)
					{
						_putchar(*(s - 1));
						count++;
					}
					break;
				}
			case '%':
				{
					_putchar('%');
					count++;
					break;
				}
			case 'd':
			case 'i':
				{
					int intv = va_arg(arg, int);

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
					break;
				}
			default:
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
