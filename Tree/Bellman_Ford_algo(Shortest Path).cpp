#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main()
{
	int n, e; //no of node and edges
	cin>>n>>e;
	vector<vector<int>> edges;
	for(int i = 0; i<e; i++){
		int u, v, wt;
		cin>>u>>v>>wt;
		edges.push_back({u,v,wt});
	}
	int source;
	cin>>source;
	bool update;
	vector<int> distance(n, INF);
	distance[source] = 0;

	for(int i = 0; i<n-1; i++){
		update = false;
		for(auto a: edges){
			int u = a[0];
			int v = a[1];
			int wt = a[2];
			if(distance[u] != INF and distance[u] + wt < distance[v])
			{
				distance[v] = min(distance[v], wt+distance[u]);
				update = true;
			}

		}
	}

	if(update == true){
		cout<<"Graph has negative weight cycle";
		return 0;
	}
	 printf("Vertex   Distance from Source\n");
	for(int i = 0; i<n; i++){
		cout<<i<<"\t\t  "<< distance[i]<<endl;
	}
}