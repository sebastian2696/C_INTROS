//Part 4 Sebastian vElasquez 
#include <stdio.h>

int main ()
{
    int n = 5, i , p[10000], x = 2, y, T;

    
    p[0]=2;
    p[1]=3;
    printf("Please enter a number\n");
    scanf("%d",&y);
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
    for (i = 0; i < x; ++i)
    {
        printf("%d ",p[i]);
    }
    printf("\n");
    return 0;
}    