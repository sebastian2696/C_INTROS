//Part 3 Sebastian vElasquez 
#include<stdio.h>

int convert_base(int n ,int b, int i[])
{    
    int x=0,y,z_1,z_2;
    const char nn[16]= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

    z_1= n % 1;
    z_2= b % 1;
    if (n<0 || b<0 || b>16 || z_1 !=0 || z_2 !=0)
    {
        return -1;
    }
    else
    {
        do 
        {
            i[x] = n % b;
           ++x;
           n = n /b;
        }    
        while (n != 0);
    
        printf("New Number !\n");

        for (--x; x >= 0; --x)
        {
        
            y = i[x];
            printf ("%c", nn[y]);
        }
        printf("\n");
        return 0;
    }    
}

int main()
{
    int n,b, i[64];
    printf("Enter a number\n");
    scanf("%d",&n);
    printf("Enter a base\n");
    scanf("%d",&b);
    
    convert_base(n,b, i);
    return 0;
}    

    

    
/* Basically the main possible errors are if either n or b are negative 
and if one of them is a decimal number because scanf for an integer has a lot of dificulty
Second the program is designed for up to base 16 so if b>16 the program will output wrong values.
I used a if statemen with OR logical connector to englobe all of this*/