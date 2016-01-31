//Part 3 Sebastian vElasquez 
#include<stdio.h>

int main()
{
    int  i=0,a,b,c=1,n,x,y,z=1;
    printf("Enter a number > 0 :\n");
    scanf("%d",&n);
    if (n<0)
    {
        printf("Since a factorial for a negative integer is not defined.\nNo negative numbers are allowed.\nPlease restart the program.\n");
    }
    else
    {
    n++;
        for (i;i<n;i++)
        {
            x=i*i;
            y=i*i*i;
            while (c<=i)
            {
                z=z*c;
                c++;
            }
            printf("%d %d %d %d\n",i,x,y,z);
        }
        return 0;
    }
}    
