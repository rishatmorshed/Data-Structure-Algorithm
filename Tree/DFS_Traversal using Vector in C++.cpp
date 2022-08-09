#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>v;
vector<int>visited;
void DFS_Traversal(int vertex, int size);

int main()
{
	int size, data, vertex;
	cout << "Enter the number of vertices: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		visited.push_back(0);
	}
	cout << "Enter Graph data in Matrix order:\n";
	for (int i = 0; i < size; i++)  // Initializing 2D vector
	{
		vector<int>row;             // Take Row Alada kore
		for (int j = 0; j < size; j++)
		{
			cin >> data;
			row.push_back(data);    // Push Element in to row
		}
		v.push_back(row);          // Push the row in 2D vector V
	}

	cout << "Enter the Starting vertex Number: ";
	cin >> vertex;
	cout << "DFS Traversal is: ";
	visited[vertex] = 1;			// Mark starting vertex as visited to 1 sign
	cout << vertex;

	DFS_Traversal(vertex, size);

	return 0;
}

void DFS_Traversal(int vertex, int size)
{
	for (int i = 0; i < size; i++)
	{
		while (v[vertex][i] != 0 && visited[i] == 0) // make sure adjacency vertices of current vertex are Not visited
		{
			visited[i] = 1;  // Make the current vertex as visited to assign 1
			cout << i;
			DFS_Traversal(i, size);
		}
	}
}