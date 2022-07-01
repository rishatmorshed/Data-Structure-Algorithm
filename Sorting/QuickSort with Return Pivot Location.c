#include<stdio.h>
#include<conio.h>

void quickSort(int A[], int first, int last);
int Partition(int A[], int first, int last);

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

    quickSort(A, 0, size - 1);
    printf("\nAfter apply QuickSort Algorithm: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}

int Partition(int A[], int first, int last)
{
    int pivot = A[last];
    int i = first-1;
    for (int j = first; j < last; j++)
    {
        if (A[j] < pivot)
        {
            i++;
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    i++;
    int temp = A[i];
    A[i] = pivot;
    A[last] = temp;
    return i;  // pivot index
}

void quickSort(int A[], int first, int last)
{
    if (first < last)
    {
        int pivotLocation = Partition(A, first, last);

        quickSort(A, first, pivotLocation - 1);
        quickSort(A, pivotLocation + 1, last);
    }
}