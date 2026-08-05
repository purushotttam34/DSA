#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            DFS(neighbor, graph, visited);
        }
    }
}

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):" << endl;

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);   // Remove this line for directed graph
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(V, false);

    cout << "DFS Traversal: ";
    DFS(start, graph, visited);

    return 0;
}