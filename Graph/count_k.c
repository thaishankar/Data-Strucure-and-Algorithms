#include<iostream>
#include<list>
using namespace std;
 
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[], int k, int d, int *count);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void DFS();    // prints DFS traversal of the complete graph
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
 
void Graph::DFSUtil(int v, bool visited[], int k, int d, int *count)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    if (k==0 && v==d)
	*count = *count + 1;
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i) {
        if(!visited[*i]) {
            DFSUtil(*i, visited, k-1, d, count);
	    visited[*i] = false;
	}
    }
}
 
// The function to do DFS traversal. It uses recursive DFSUtil()
void Graph::DFS()
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];


    for (int i = 0; i < V; i++)
        visited[i] = false;

   int count = 0, k = 2, d = 3, v = 0;
 
    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    DFSUtil(v, visited, k, d, &count);

    cout << "Walks with k edges = "<<count<<endl;
}
 
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
 
    cout << "Following is Depth First Traversal\n";
    g.DFS();
 
    return 0;
}

