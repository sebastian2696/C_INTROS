//Part 2 Sebastian vElasquez 
#include<stdio.h>

int factorial_4(int n)
{
    int  i=1,x,y,z=1;
    n++;
    printf("0 0 0 1\n");   
    LOOP:
        x=i*i;
        y=i*i*i;
        z=z*i;
        printf("%d %d %d %d\n",i,x,y,z);
        i++;
    if (i<n)
    {
    goto LOOP;
    }
    return 0;
}

int factorial_3(int n)
{
    int  i=0,c=1,x,y,z=1;
    n++;
    while(i<n)
    {
        x=i*i;
        y=i*i*i;
        while (c<=i)       
        {
            z=z*c;
            c++;
        }
        printf("%d %d %d %d\n",i,x,y,z);
        i++;
    }
    return 0;
}

int factorial_2(int n)
{
    int  i=0,c=1,x,y,z=1;
    n++;
    do 
    {
        x=i*i;
        y=i*i*i;
        
        if (i==0){
            z=1;
        printf("%d %d %d %d\n",i,x,y,z);
        }
        else
        {
            do
        
            {
                z=z*c;
                c++;
            }
            while (c<i);
            printf("%d %d %d %d\n",i,x,y,z);
        }
    i++;
    }
    
    while(i<n);
    return 0;
    
}

int factorial(int n)
{
    int  i=0,x,y,z=1;
    printf("0 0 0 1\n");
    n++;
    for (i=1;i<n;i++)
    {
        x=i*i;
        y=i*i*i;
        z=z*i; 
        printf("%d %d %d %d\n",i,x,y,z);
    }
    return 0;
}

int main(void)
{
    int  n;
    printf("Enter a number > 0 :\n");
    scanf("%d",&n);
    if (n<0)
    {
        printf("Since a factorial for a negative integer is not defined.\nNo negative numbers are allowed.\nPlease restart the program.\n");
    }
    else
    {
    factorial(n); //ok
    factorial_2(n); //ok
    factorial_3(n); //ok
    factorial_4(n); //ok
    }
    return 0;
}

