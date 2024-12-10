#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

// Function to initialize the adjacency matrix
void initializeGraph(int adj[100][100], int V) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0; // No edge initially
        }
    }
}

// Function to add an edge to the adjacency matrix
void addEdge(int adj[100][100], int u, int v, int w) {
    adj[u][v] = w; // Directed graph
}

// Function to find the vertex with the minimum distance
int findMinDistance(int distance[], bool visited[], int V) {
    int minDist = INT_MAX, minIndex = -1;
    for (int i = 0; i < V; i++) {
        if (!visited[i] && distance[i] < minDist) {
            minDist = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Function to print the shortest path from the source to a given vertex
void printPath(int predecessor[], int vertex) {
    if (predecessor[vertex] == -1) {
        cout << vertex; // Start of the path
        return;
    }
    printPath(predecessor, predecessor[vertex]);
    cout << " -> " << vertex; // Append the current vertex
}

// Dijkstra's Algorithm implementation
void dijkstra(int adj[100][100], int V, int src) {
    int distance[100];    // Array to store shortest distances from the source
    bool visited[100];    // Array to track visited vertices
    int predecessor[100]; // Array to store the predecessor of each vertex

    // Step 1: Initialize all distances and visited array
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
        predecessor[i] = -1; // No predecessor initially
    }
    distance[src] = 0; // Distance to the source is 0

    // Step 2: Main Dijkstra's algorithm loop
    for (int count = 0; count < V - 1; count++) {
        int u = findMinDistance(distance, visited, V); // Find the unvisited vertex with the smallest distance
        if (u == -1) break; // No more reachable vertices
        visited[u] = true;

        // Update distances for adjacent vertices
        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 && !visited[v] && distance[u] + adj[u][v] < distance[v]) {
                distance[v] = distance[u] + adj[u][v];
                predecessor[v] = u; // Update predecessor
            }
        }
    }

    // Step 3: Print the shortest distances and paths
    cout << "Vertex\tDistance\tPath\n";
    for (int i = 0; i < V; i++) {
        if (distance[i] == INT_MAX) {
            cout << i << "\tINF\t\tNo Path\n";
        } else {
            cout << i << "\t" << distance[i] << "\t\t";
            printPath(predecessor, i); // Print the path from source to vertex `i`
            cout << endl;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    int adj[100][100]; // Adjacency matrix

    // Initialize the graph
    initializeGraph(adj, V);

    cout << "Enter the number of edges: ";
    cin >> E;

    // Input the edges
    cout << "Enter the edges (u v w) where u and v are vertices (0-based) and w is the weight:\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(adj, u, v, w);
    }

    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    if (startVertex < 0 || startVertex >= V) {
        cout << "Invalid starting vertex. Exiting...\n";
        return 1;
    }

    cout << "\nDijkstra's Algorithm starting from vertex " << startVertex << ":\n";
    dijkstra(adj, V, startVertex);

    return 0;
}
