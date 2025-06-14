#include <stdio.h>

// This program converts Celsius to Fahrenheit
int main() 
{
    int cel;
    for (cel = 0; cel <= 100; cel = cel + 20)
        printf("%4d %6.1f\n", cel, ((cel * (9.0/5.0)) + 32.0));
}