#include "main.h"

/**
 * print_int - print integer to stdout and count
 * @n: integer to print
 *
 * Return: integer count
 */

int print_int(long int n)
{
	long int counter = 0;
	long int rev = 1;
	long int num;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		counter += 1;
	}

	num = n;
	while (n / rev >= 10)
	{
		rev = rev * 10;
	}

	while (rev > 0)
	{
		_putchar((num / rev) + '0');
		num %= rev;
		rev /= 10;
		counter += 1;
	}
	return (counter);
}

