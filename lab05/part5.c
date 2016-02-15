//Part 5 Sebastian vElasquez 
#include <stdio.h>

int is_prime(int y)
{
    int n = 5, i , p[100000], x = 2, T,q=0;
    
    p[0]=2;
    p[1]=3;
    for ( ; n <= y; )
    {
        T = 1;
        for ( i = 1;  n/p[i] >= p[i]; ++i)
        {
            if ( n % p[i]==0)
            {
                T = 0;
                break;
            }
        }
        if (T == 1)
        {
            p[x] = n;
            ++x;
        }
    n = n+2;    
    }
    x--;
    for (i = 0; i < x; ++i)
    {
       if (y%p[i] == 0)
       {
        q=1;
        break;
       }
    }
    if (q == 0){
        printf("Prime");
    }
    else
    {
        printf("Not Prime");
    }
    printf("\n");
    return 0;
}    

int main ()
{
    int y;
    printf("Input a number to check for primality!\n");
    scanf("%d",&y);
    printf("%d is ", y);
    is_prime(y);
    return 0;
}    

/*Segmentaion Fault appears as an error when the array exceeds 10000000.
This means that the program will override memory or attemp to access memory that is not designed for this use. */