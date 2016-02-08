// Part4 Sebastian Velasquez

#include <stdio.h>
#include <math.h>
#include <float.h>


int mysqurt(double n)
{
    int i = 0;
    double x, y;
    x = n / 2;
    printf("The square root of %lf:\n", n);
    if (n > 0)
    {
        while (i<1000)
        {
            y = x - (x*x - n)/(2*x);
            x = y;
            i++;
        }
        printf("%0.16lf \n", y);
    }    
    else  if (n == 0)  
    {
        printf("0\n");
    }
    else
    {
        printf("NaN\n");
    }    
    return 0;
}

int main (void)
{

    double n;

    printf("Newton-Raphson Method.\n");
    printf("Please enter a number: ");
    scanf("%lf", &n);
    mysqurt(n);
    return 0;
}

/* The Newton-Raphson method uses the equation x^2= number and solve for x to find the square root. 
Using a guess in order to narrow down the correct and compute the equation y = x - (x*x - n)/(2*x) the result will be a more precise number.
the idea is to set this equation to limit o, which corresponds to the actual real value for the square root. By narrowing x, smaller and smaller, we effectively create the limit.
The loop mimic this idea of turning x infinetly small. Since the number will really big in terms of decimal places. A type double grants a 64 bit encoding, which gives us about 16 decimal numbers (52 bits )
*/
