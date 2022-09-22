#include<iostream>
#include <list>
using namespace std;
class Graph
{	int V;
	list<int> *adj;
public:
	Graph(int V); 
	void addEdge(int v, int w);
	void BFS(int s); 
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
	enum c{WHITE,GREY,BLACK};
	int colour[V], distance[V],pre[V];
	
for(int i = 0; i < V; i++){
        colour[i]=WHITE;
        distance[i]=-1;
        pre[i]=0;
    }
    // Create a queue for BFS
	list<int> queue;
    colour[s]=GREY;
    distance[s]=0;
    pre[s]=0;
		
	queue.push_back(s);

	// 'i' will be used to get all adjacent vertices of a vertex
	list<int>::iterator i;

	while(!queue.empty())
	{
		// Dequeue a vertex from queue and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
            if(colour[*i]==WHITE){
                colour[*i]=GREY;
                distance[*i]++;
                pre[*i]=s;
            queue.push_back(*i);
            }
            colour[s]=BLACK;
	}}}

// Driver program to test methods of graph class
int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Breadth First Traversal starting from vertex 2\n";
	g.BFS(2);
    return 0;
}
