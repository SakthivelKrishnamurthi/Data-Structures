#include <bits/stdc++.h>

using namespace std;

class Graph{
	public:
		int V;
		vector<vector<int> >graph;
		
		Graph(int v);
		void addEdge(int u,int v,int w);
		void printArr(int parent[],vector<vector<int> >& graph);
		int minDis(int key[],bool sptset[]);
		void prims();
};

Graph::Graph(int v)
{
	this->V = v;
	graph.resize(v,vector<int>(v,0));
}


void Graph::printArr(int parent[],vector<vector<int> >& graph)
{
	cout<<"Edge"<<"\t\t\t\t"<<"Weight\n";
	for(int i=1;i<V; i++)
	{
		cout<<parent[i]<<"-"<<i<<"\t"<<graph[i][parent[i]]<<"\n";
	}
}

int Graph::minDis(int key[],bool sptset[])
{
	int min = INT_MAX,min_dis;
	for(int i=0; i<V; i++)
	{
		if(sptset[i]==false and key[i] < min)
		{
			min = key[i];
			min_dis = i;
		}
	}
	return min_dis;
}

void Graph::prims()
{
	int parent[V],key[V];
	bool sptset[V];
	for(int i=0; i<V; i++)
	{
		key[i] = INT_MAX;
		sptset[i] = false;
	}
	parent[0] = -1;
	key[0] = 0;
	
	for(int count=0; count<V-1; count++)
	{
		int u = minDis(key,sptset);
		
		sptset[u] = true;
		
		for(int v=0; v<V; v++)
		{
			if(!sptset[v] && graph[u][v] && graph[u][v] < key[v])
			{
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}
	
	printArr(parent,graph);
}

int main()
{
	Graph g(6);
    g.addEdge(5, 2, 4);
    g.addEdge(5, 0, 6);
    g.addEdge(4, 0, 7);
    g.addEdge(4, 1, 4);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 1, 2);
    
    g.prims();
    return 0;
}
