#include<bits/stdc++.h>
#include<iostream>
#include<vector>
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
	int n, e; // n is total no of nodes, e is total number edges
	cin >> n >> e;
  	vector<pair<int, pair<int, int> > > edges; /*creating vector for 
						sort edges based on weight.
  					        and kon duita noder moddhe edge ache*/

	for(int i = 0; i<e; i++)
	{
		int u, v, wt;
		cin>> u >> v >> wt;
		edges.push_back({wt, {u , v}});
	}

	sort(edges.begin(), edges.end());

	for(int i = 0; i<n; i++) make(i);


	int total_weight = 0;
	for(auto &edge : edges) /* find minimum weight and
				   check would it make a cycle or not*/ 
	{
		int wt = edge.first; 		 //weight of edge
		int u = edge.second.first;   //first vertex of edge
		int v = edge.second.second;  //second vertex of edge
		if(find(u) == find(v)) // find u and v parent is same of not
		{
			continue;  /*breaks one iteration (in the loop)
				     and continues with the next iteration in the loop */
		}
		else{
			Union(u, v);
		}
		total_weight += wt;
		cout<< u <<" <-> "<< v <<" = "<< wt <<endl;
	}	
	cout<<"The minimum weight is : "<<total_weight<<endl;
}
