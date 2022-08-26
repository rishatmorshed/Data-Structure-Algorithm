#include<iostream>
using namespace std;
const int N=1e5+10;

int parent[N];
int size[N];

void make(int v)
{	
	parent[v] = v; //make independent set
	size[v] = 1; //initially each node is a single group
}
int find(int v)
{
	if(v == parent[v]) //if v is independent means the parent of v then return v
	{
		return v;
	}
	else{
		return parent[v] = find(parent[v]); /*if v is not parent of v
								then find the parent of v and 
								all the node which are visited 
								during find the root stored in 
								parent[v] and return 
								(Its called path compress)*/
	}
}
void Union(int A, int B)
{
	A = find(A); // here find the root of A
	B = find(B); // here find the root of B
	if(A != B)  // if they are not in same set/group
	{
		if(size[A] < size[B]) // This is called uion by size
		{
			swap(A, B);
		}
		parent[B] = A; // Then make parent of B is A (union two node)
		size[A] = size[A] + size[B];

	}
}

int main()
{
	int n, edge;
	cin>>n>>edge; 
	for(int i = 0; i<n; i++)
	{
		make(i);
	}
	while(edge--)
	{
		int u, v;
		cin >> u >> v;
		Union(u, v);
	} 
	int connected_component = 0;
	for(int i = 0; i<n; i++){
		if(find(i) == i){
			connected_component++;
		}
	}
	cout<<connected_component<<endl;

}