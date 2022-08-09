#include<stdio.h>
#include<conio.h>

int A[10][10], visited[10], size;
void BFS_Traversal(int vertex);

int main()
{
	int i, j, vertex;
	printf("Enter the Number of Vertices: ");
	scanf_s("%d", &size);
	for (i = 0; i < size; i++)
	{
		visited[i] = 0;
	}
	printf("Enter the grapg element in matrix order:\n");
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			scanf_s("%d", &A[i][j]);
		}
	}
	printf("Enter the starting vertex number: ");
	scanf_s("%d", &vertex);
	printf("\nDFS traversal is : ");
	visited[vertex] = 1; // Mark strating vertex as visited
	printf("%d", vertex);
	BFS_Traversal(vertex);

	return 0;
}

void BFS_Traversal(int vertex)
{
	for (int i = 0; i < size; i++)
	{
		while (A[vertex][i] != 0 && visited[i] == 0) // Adjecent to current vertex and which are not visited
		{
			visited[i] = 1; // Make visited vertex as 1
			printf("%d", i);
			BFS_Traversal(i);
		}
	}
}