// Part1 Sebastian Velasquez

#include <stdio.h>

long int random(void);

void find_maximum(int A[], int n, int *idx_max, int *max_val)
{
    int i,m;
    m = A[0];
    for(i=0; i<n; i++)
    {
        if (A[i] > m)
        {
            *idx_max = i;
            *max_val = A[i];
            m = A[i];
        }
    }

}

void find_minimum(int A[], int n, int *idx_min, int *min_val)
{
    int i,m;
    m = A[0];
    for(i=0; i<n; i++)
    {
        if (A[i] < m)
        {
            *idx_min = i;
            *min_val = A[i];
            m = A[i];
        }
    }

}

int main()
{
    int *idx_max, *max_val, *min_val, *idx_min;
    int A[10000], n=10000,i;
    for (i = 0; i < n; i++)
    {
        A[i] =  random();
    }
    idx_max = &n;
    max_val = A;
    idx_min = &n;
    min_val = A;
    find_maximum(A, n, idx_max, max_val);
    printf("The maximum is %d at position A[%d]\n",*max_val,*idx_max);
    find_minimum(A, n, idx_min, min_val);
    printf("The minimum is %d at position A[%d]\n",*min_val, *idx_min);
    return 0;
}