#include<stdio.h>
#include<conio.h>

void bfs(int vertex);
int A[10][20], queue[10], visited[10], size, front = -1, rear = -1;


int main()
{
	int vertex, i, j;
	printf("Enter the total number of vertex: ");
	scanf_s("%d", &size);
	for (i = 0; i < size; i++)
	{
		visited[i] = 0;				// make all visited array elements as 0. mean not visited
	}

	printf("Enter the Graph data in matrix order:\n");
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			scanf_s("%d", &A[i][j]);
		}
	}

	printf("Enter the number of starting vertex: ");
	scanf_s("%d", &vertex);
	rear = front = 0;  // when we insert data in queue then both rear and front will in 0 index
	queue[rear] = vertex; // Insert form rear. 

	printf("BFS traversal IS: ");
	visited[vertex] = 1; // make the starting vertex as visited
	printf("%d ", vertex);
	bfs(vertex);

}

void bfs(int vertex)
{
	for (int i = 0; i < size; i++) // To check all the vertex from the graph
	{
		if (A[vertex][i] != 0 && visited[i] == 0)
		{
			rear = rear + 1;
			queue[rear] = i;
			visited[i] = 1; // make the vertex as visited
			printf("%d ", i);
		}
	}
	front = front + 1; // Now remover top element from the queue, so front++
	if (front <= rear) // As long as there are element in the queue.
	{
		bfs(queue[front]);// call bfs with the vertex number, which is at the front of the queue
	}
}