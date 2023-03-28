#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2, l3,l33,l4,l44,l5,l55,l6,l66;
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);


   l3 = _printf("Negative:[%d]\n", -762534);
   l33= printf("Negative:[%d]\n", -762534);
   printf("Ours: %d, normal: %d\n", l3, l33);

   l4 = _printf("Character:[%c]\n", 'H');
   l44 =  printf("Character:[%c]\n", 'H');
   printf("Ours: %d, normal: %d\n", l4, l44);

    l5 = _printf("String:[%s]\n", "I am a string !");
    l55 =  printf("String:[%s]\n", "I am a string !");
    printf("Ours: %d, normal: %d\n", l5, l55);
    
    l6 = _printf("Percent:[%%]\n");
    l66 = printf("Percent:[%%]\n");
   printf("Ours: %d, normal: %d\n", l6, l66);

    return (0);
}
