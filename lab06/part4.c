
#include <stdio.h>

int find_string(const char *haystack, const char *needle)
{
    int index = 0, i = 0, w = 0;
    
    LOOP:
    while ( *needle != *(haystack + index) && haystack[index] != '\0')
    {
        index++;
    }
    if (haystack[index] == '\0')
    {
        return -1;
    }
    while ( needle[w] != '\0' )
    {
        w++;
    }
    while ( needle[i] == haystack[index] &&  haystack[index] != '\0' && needle[i] != '\0')
    {
        i++;
        index++;
    }
    if (haystack[index] != '\0' && w != i)
    {
        i=0;
        w=0;
        goto LOOP; 
    }
    //printf("%d",index);
    if (*(needle + i-1) == *(haystack + index-1) && w == i)
    {
        index = index - i;
       
        return index ;
    }
    
    else return -1;
}    

int main (void)
{
    char *haystack, *needle;
    int index;
   // char A[]= "a charterboxhat", B[] = "hat";
    char A[100],B[100];
    printf("Enter a Phrase or Word\n");
    gets(A);
    printf("Enter a Word\n");
    gets(B);
    haystack = A;
    needle = B;
    index = find_string (haystack, needle);
    printf("%d\n",index);
    return 0;
}

/* We do not have to pass the size of the arraw because the are using pointers. 
Pointer are defined as variables not as arrays. 
The way the problem is set up A[0] = *haystack and A[1] = *(haystack + 1).*/ 

