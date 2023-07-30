#include <bits/stdc++.h>

using namespace std;

class Graph{
	public:
		int V;
		vector<vector<int> > graph;
		vector<list<int> > adj;
		
		Graph(int v);
		void addEdge(int u,int v,int w);
		void delEdge(int u,int v);
		void BFS(int s);
		void DFS(int s);
		void topologicalSort();
		void topSort(int v,vector<bool>& visited,stack<int>& Stack);
		void print(int dist[]);
		int minDist(int dist[], bool sptSet[]);
		void Dijkstra(vector<vector<int> >& graph,int src);
		void dijkstra(int src);
};

Graph::Graph(int v)
{
	this->V = v;
	graph.resize(v,vector<int>(v,0));
	adj.resize(v,list<int>());
}

void Graph::addEdge(int u,int v,int w)
{
	graph[u][v] = w;
	graph[v][u] = w;
	adj[u].push_back(v);
}

void Graph::delEdge(int u,int v)
{
	graph[u][v] = 0;
	graph[v][u] = 0;
}

void Graph::BFS(int s)
{
	vector<bool> visited(graph[0].size(),false);
	queue<int> q;
	cout<<"\n---------------BREADTH FIRST TRAVERSAL-----------------------\n";
	q.push(s);
	visited[s] = true;
	while(!q.empty())
	{
		int ad = q.front();
		cout<<ad<<" ";
		q.pop();
		for(int i = 0; i < graph[ad].size(); i++)
		{
		
			if(graph[ad][i] > 0 && !visited[i])
			{
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

void Graph::DFS(int s)
{
	vector<bool> visited(graph[0].size(),false);
	stack<int> st;
	cout<<"\n-------------------DEPTH FIRST TRAVERSAL-------------------\n";
	st.push(s);
	visited[s] = true;
	while(!st.empty())
	{
		int ad = st.top();
		cout<<ad<<" ";
		st.pop();
		
		for(int i=0; i<graph[ad].size();i++)
		{
			if(graph[ad][i] > 0 && !visited[i])
			{
				st.push(i);
				visited[i] = true;
			}
		}
	}
	
}

void Graph::topSort(int v,vector<bool>& visit, stack<int>& Stack)
{
	visit[v] = true;
	list<int>::iterator i;
	for(i = adj[v].begin();i!=adj[v].end();++i)
	{
		if(!visit[*i])
		{
			topSort(*i,visit,Stack);
	    }
	}
	Stack.push(v);
}

void Graph::topologicalSort()
{
	stack<int> Stack;
	vector<bool> visit(graph[0].size(),false);
		
	for(int i=0; i<V; i++)
	{
		if(visit[i]==false)
		{
			topSort(i,visit,Stack);
		}
	}
	
	cout<<"\n--------------------TOPOLOGICAL SORTING---------------------\n";
	
	while(!Stack.empty())
	{
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
}

int Graph::minDist(int dist[], bool sptSet[])
{
  
    // Initialize min value
    int min = INT_MAX, min_index;
  
    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
  
   }
    return min_index;
}

void Graph::print(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dist[i] << endl;
}

void Graph::Dijkstra(vector<vector<int> >& graph,int src)
{
	int dist[V];
	
	bool sptset[V];
	
	for(int i=0; i<V; i++)
	{
		dist[i] = INT_MAX;
		sptset[i] = false;
	}
	
	dist[src] = 0;
	
	for(int count=0; count<V-1; count++)
	{
		int u = minDist(dist,sptset);
		
		sptset[u] = true;
		
		for(int v=0; v<V; v++)
		{
			if (!sptset[v] && graph[u][v]
                && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
		}
	}
	
	print(dist);

}

void Graph::dijkstra(int src)
{
	Dijkstra(graph,src);
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
	g.BFS(0);
	g.DFS(0);
	g.topologicalSort();
	g.dijkstra(0);
	return 0;
}
