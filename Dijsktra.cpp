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
    // Uncomment the next line for an undirected graph:
    // adj[v][u] = w; 
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

// Dijkstra's algorithm function
void dijkstra(int adj[100][100], int V, int src) {
    int distance[100];    // Array to store shortest distances from src
    bool visited[100];    // Array to keep track of visited vertices
    int predecessor[100]; // Array to store the predecessor of each vertex

    // Initialize all distances as infinite and visited array as false
    for (int i = 0; i < V; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
        predecessor[i] = -1; // No predecessor initially
    }

    distance[src] = 0; // Distance to source is 0

    // Main loop of Dijkstra's algorithm
    for (int count = 0; count < V - 1; count++) {
        // Find the unvisited vertex with the smallest distance
        int u = findMinDistance(distance, visited, V);
        if (u == -1) break; // If no valid vertex found, exit loop
        visited[u] = true; // Mark as visited

        // Update the distance and predecessor for adjacent vertices
        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 && !visited[v] && distance[u] + adj[u][v] < distance[v]) {
                distance[v] = distance[u] + adj[u][v];
                predecessor[v] = u;
            }
        }
    }

    // Output the distances and predecessors
    cout << "Vertex\tDistance from Source\tPredecessor\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << distance[i] << "\t\t\t";
        if (predecessor[i] == -1) {
            cout << "NIL" << endl;
        } else {
            cout << predecessor[i] << endl;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    if (V > 100) {
        cout << "Maximum number of vertices exceeded. Exiting...\n";
        return 1;
    }
    int adj[100][100];
    // Initialize the graph
    initializeGraph(adj, V);
    cout << "Enter the number of edges: ";
    cin >> E;
    // Input the edges and weights
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

    cout << "Dijkstra's Algorithm starting from vertex " << startVertex << ":\n";
    dijkstra(adj, V, startVertex);

    return 0;
}

