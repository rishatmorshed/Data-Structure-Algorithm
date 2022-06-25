#include<stdio.h>
#include<conio.h>

void MergeSort(int A[], int lb, int ub);
void Merge(int A[], int lb, int mid, int ub);

int main()
{
	int A[10], size;
	printf("Enter the size of the Array: ");
	scanf_s("%d", &size);

	printf("Enter the Array Elements:\n");
	for (int i = 0; i < size; i++)
	{
		scanf_s("%d",&A[i]);
	}
	printf("Array Elements are: ");
	for (int j = 0; j < size; j++)
	{
		printf("%d ",A[j]);
	}
	printf("\nAfter Applying Merge Sort ALGO: ");

	MergeSort(A, 0, size-1);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", A[i]);
	}

	return 0;
}

void MergeSort(int A[], int lb, int ub)
{
	int mid;
	if (lb < ub)
	{
		mid = (lb + ub) / 2;
		MergeSort(A, lb, mid);
		MergeSort(A, mid + 1, ub);
		Merge(A, lb, mid, ub);
	}
}

void Merge(int A[], int lb, int mid, int ub)
{
	int i, j, k, temp[20];
	i = lb;
	j = mid + 1;
	k = lb;
	while (i <= mid && j <= ub)
	{
		if (A[i] <= A[j])
		{
			temp[k] = A[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = A[j];
			j++;
			k++;
		}
	}

	if (i > mid)
	{
		while (j <= ub)
		{
			temp[k] = A[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			temp[k] = A[i];
			i++;
			k++;
		}
	}
	for (k = lb; k <= ub; k++)
	{
		A[k] = temp[k];
	}	
}