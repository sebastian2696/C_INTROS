//Part 1 Sebastian vElasquez 
#include <stdio.h>

int fibonacci(int n)
{
    int Fibonacci[n],i,j=0;
    Fibonacci[0] = 0;
    Fibonacci[1] = 1;
    for ( i = 2; i<n ;++i)
    {
        Fibonacci[i] = Fibonacci[i-2] + Fibonacci[i-1];
    }
    for (i = 1; i < n; ++i)
    {
    printf("Fibonacci[%d] = %d\n", j, Fibonacci[i]);
    j++;
    }
    return 0;
}

int main (void)
{
    int n;
    printf("Enter a number\n");
    scanf("%d",&n);
    fibonacci(n);
    return 0;
}


