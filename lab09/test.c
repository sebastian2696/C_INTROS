
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
void merge(char* list[], int left, int mid, int right)
{
	int leftEnd = mid-left+1; //end point of first listay
	int rightStart = right-mid; //starting point of new right listay
	
	char** leftArray = malloc(sizeof(char *)*leftEnd);//making new left listay
	
	char** rightArray = malloc(sizeof(char *) *rightStart);
	
	
	int i;
	
	for(i = 0; i < leftEnd; i++)
	{
		//copying the left strings into the new lft listay
		leftArray[i]=malloc(sizeof(list[left+i]));//giving the memory space to hold the string
		strcpy(leftArray[i],list[left+i]);//setting the value of lA[i] = list[left+i]
	}
	
	for(i=0; i < rightStart; i++)
	{
		//same process for the right listay
		rightArray[i] = malloc(sizeof(list[mid+i+1]));
		strcpy(rightArray[i], list[mid+i+1]);
	}
	
	int j = 0,k = left;
	i=0;
	
	while(i < leftEnd && j < rightStart)
	{
		if(strcmp(leftArray[i],rightArray[j]) < 0)strcpy(list[k++], leftArray[i++]);
		else strcpy(list[k++],rightArray[j++]);
	}
	
	//to handel uneven left and right sides
	
	while(i < leftEnd)
	{
		strcpy(list[k], leftArray[i]);
		k++;
		i++;
	}
	while(j < rightStart)
	{
		strcpy(list[k],rightArray[j]);
		k++;
		j++;
	}
}
void partition(char* list[], int left, int right)
{
	if(left<right)
	{
		
		int mid = (left + right) / 2;//middle
		//divide the list in half until left=right
		partition(list,left,mid);
		partition(list,mid+1,right);
		merge(list,left,mid,right);
	}
}
int main(int argc, char *argv[])
{
	char** list = malloc(sizeof(char *)* 1000);//default to size 1000	
	int index = 0;
	int exit_status = 0;
	FILE *fp;
	if (argc < 2) {
		fp = stdin;
	}
	else {
		fp = fopen(argv[1], "r");
		if (!fp) {
			fprintf(stderr, "Error opening %s: %s\n", argv[1], strerror(errno));
			
			exit(1);
		}
	}
	size_t n = 0;
	char *lineptr = 0;
	
	for (;;) {
		
		ssize_t rc = getline(&lineptr, &n, fp);
		if (rc < 0) {
			break;
		}
		if (rc > 0) {
			
			list[index] = malloc(sizeof(char *)*n);
			strcpy(list[index],lineptr);
		
			index++;
		}
		free(lineptr);
		lineptr = 0;
		n = 0;
	}
	
	
	
	partition(list,0,index-1);
	
	if (ferror(fp)) {
		fprintf(stderr, "Error reading %s: %s\n", argv[1], strerror(errno));
		exit_status = 1;
	}
	
	
	printf("\nSorted List:\n");
	int j;
	for(j = 0; j < index; j++)
	{
		printf("%s",list[j]);
	}
	fclose(fp);
	exit(exit_status);
	return 0;
}