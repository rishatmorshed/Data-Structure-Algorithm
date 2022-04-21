#include<stdio.h>
#include<conio.h>
#include<string.h>
int manually();
int builtIn();

void main()
{
	int size1, size2;
	size1 = manually();
	printf("String length calculated manually = %d", size1);
	printf("\n");
	size2 = builtIn();
	printf("String length calculated using built in function: %d", size2);
	_getch();
}
	
int manually()
{
	int i=0;
	char A[10];
	printf("Enter String: ");
	gets_s(A);
	while (A[i] != '\0')
	{
		i++;
	}
	return i;
}

int builtIn()
{
	char B[10];
	int size;
	printf("Enter another string: ");
	gets_s(B);
	size = strlen(B);
	return size;
}