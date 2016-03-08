//Part2 Sebastian Velasquez

#include <stdio.h>

int x_to_the_n (int x, int n)
{
    int i,p;
    p = x;
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        n = -n;
    }
    for(i = 1; i < n; i++)
    {
        p = p*x;
    }
    return p;
}
int check (int n)
{
    if(n > 30 || n< -30)
    {
        return -1;
    }
    return 0;
}

int main()
{
    int x,n,y;
    float e;
    printf("Input a number\n");
    scanf("%d",&x);
    printf("elevated to the\n");
    scanf("%d",&n);
    y =check(n);
    if (y == -1)
    {
        printf("The result of %d^%d will be loo large to be processed.\nPlease restart.\n",x,n);
        return -1;
    }
    printf("is ");
    x = x_to_the_n (x , n );
    if (n < 0)
    {
        e = 1 / (float)x;
        printf("%f\n",e);
    }
    else 
    {
        printf("%d\n",x);
    }
    return 0;
}