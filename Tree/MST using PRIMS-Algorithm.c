#include<stdio.h>
#include<conio.h>
#include <climits>

int Weight[10][10], size;
void Prims_Algo(int Weight[10][10], int vertex);
int min_key(int MST[10], int visited[10]);

int main()
{
	int vertex;
	printf("Enter the total number of vertex: ");
	scanf_s("%d", &size);
	
	printf("Enter the graph data in matrix order:\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf_s("%d", &Weight[i][j]);
		}
	}
	printf("Enter the starting vertex: ");
	scanf_s("%d", &vertex);
	
	Prims_Algo(Weight, vertex);
	
	return 0;
}

void Prims_Algo(int Weight[10][10], int vertex)
{
	int parent[10], key[10];
	int visited[10];
	for (int i = 0; i < size; i++)
	{
		key[i] = INT_MAX;
		visited[i] = 0;
		parent[i] = -1;
	}
	key[0] = 0;  //Include 1st vertex value as 0
	parent[0] = -1; // 1st node is always root node, and it has no parent

	for (int i = 0; i < size - 1; i++)
	{
		int u = min_key(key, visited);
		visited[u] = 1;
		for (int v = 0; v < size; v++)
		{
			if (Weight[u][v] != 0 && visited[v] == 0 && Weight[u][v] < key[v])
				/*This condition find the adjecent node of u is visited or not
				if not visited then check weight of u,v edge is less adjacent edge*/
			{
				parent[v] = u;         // Make u as a parent node of v
				key[v] = Weight[u][v]; // update the edge weight of u,v in v node
			}
		}
	}
	
	int min_weight = 0;
	printf("Edge \tWeight\n");
	for (int i = 1; i < size; i++)
	{
		printf("%d - %d \t %d\n", parent[i], i, Weight[i][parent[i]]);
		min_weight = min_weight + Weight[i][parent[i]];
	}
	printf("Total Minimum Weight is: %d", min_weight);
}

int min_key(int key[10], int visited[10])
{
	int min = INT_MAX, minimum_index;
	for (int i = 0; i < size; i++)
	{
		if (visited[i] == 0 && key[i] < min) /*Find the minimum weight from all the 
											   adjacent nodes. 
											   This condition looking for the nodes which are
											   not included in the visited array*/
		{
			min = key[i];
			minimum_index = i;
		}
	}
	return minimum_index;  // first it return 0 to the calling function
}

