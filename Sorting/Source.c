#include<stdio.h>
#include<conio.h>

void quickSort(int A[], int first, int last);

int main()
{
	int A[10], size;
	printf("Enter the size of the Array: ");
	scanf_s("%d", &size);
	printf("Enter the Array elements:\n");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d", &A[i]);
	}
	printf("Array elements are: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", A[i]);
	}

	quickSort(A, 0, size-1);
	printf("\nAfter apply QuickSort Algorithm: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", A[i]);
	}

	return 0;
}

void quickSort(int A[], int first, int last)
{
	if (first < last)
	{
		int i, j, pivot, temp;
		i = first;
		j = last;
		pivot = first;
		while (i < j)
		{

			while (A[pivot] >= A[i] && i<last)
			{
				i++;
			}
			while (A[j] > A[pivot])
			{
				j--;
			}
			if (i < j)
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
		temp = A[pivot];
		A[pivot] = A[j];
		A[j] = temp;
		quickSort(A, first, j - 1);
		quickSort(A, j + 1, last);
	}
}