//Part3 Sebastian Velasquez 

#include <stdio.h>

long array_sum(int A[], unsigned int n)
{
    int array_sum, i;
    for (i = 0; i < n; i++)
    {
        array_sum += A[i];
            
    }

    return array_sum;
}

int main()
{
    unsigned int n;
    int i, A[1000];
    printf("How many number do you want to add?\n"); 
    scanf("%d", &n);
    if (n < 1000)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
        }
    }
    else
    {
        printf("The program cannot function with 1000 or more numbers.\nTry Again");
    }
    printf("%ld\n",array_sum(A,n));
    return 0;
}
