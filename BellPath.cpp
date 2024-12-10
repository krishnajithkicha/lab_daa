#include <iostream>
#include <climits> // For INT_MAX

using namespace std;

// Function to implement Bellman-Ford algorithm
bool bellmanFord(int vertices, int edges, int edgeList[][3], int source, int destination) {
    // Step 1: Initialize distance and parent arrays
    int distance[vertices];
    int parent[vertices]; // To store the shortest path

    for (int i = 0; i < vertices; i++) {
        distance[i] = INT_MAX; // Set all distances to "infinity"
        parent[i] = -1;        // Initialize parent as -1 (no predecessor)
    }
    distance[source] = 0; // Distance to source is 0

    // Step 2: Relax edges (vertices - 1) times
    for (int i = 0; i < vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            int from = edgeList[j][0];
            int to = edgeList[j][1];
            int weight = edgeList[j][2];

            // Relax the edge if a shorter path is found
            if (distance[from] != INT_MAX && distance[from] + weight < distance[to]) {
                distance[to] = distance[from] + weight;
                parent[to] = from; // Update the parent of `to`
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (int j = 0; j < edges; j++) {
        int from = edgeList[j][0];
        int to = edgeList[j][1];
        int weight = edgeList[j][2];

        // If further relaxation is possible, a negative cycle exists
        if (distance[from] != INT_MAX && distance[from] + weight < distance[to]) {
            return false; // Negative cycle detected
        }
    }

    // Step 4: Print the shortest path and distances
    if (distance[destination] == INT_MAX) {
        cout << "No path from source to destination.\n";
    } else {
        // Reconstruct the path using the parent array
        int path[vertices]; // To store the path
        int pathIndex = 0;
        for (int v = destination; v != -1; v = parent[v]) {
            path[pathIndex++] = v; // Store the path in reverse order
        }

        // Print the path in the correct order
        cout << "Shortest path from " << source << " to " << destination << ":\n";
        for (int i = pathIndex - 1; i >= 0; i--) {
            cout << path[i];
            if (i > 0) cout << " -> ";
        }
        cout << "\nDistance: " << distance[destination] << endl;
    }

    return true; // No negative cycle detected
}

int main() {
    int vertices, edges;

    // Input: number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // Input: edges in the format {from, to, weight}
    int edgeList[edges][3];
    cout << "Enter the edges (from to weight):\n";
    for (int i = 0; i < edges; i++) {
        cin >> edgeList[i][0] >> edgeList[i][1] >> edgeList[i][2];
    }

    // Input: source and destination vertices
    int source, destination;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> destination;

    // Run Bellman-Ford algorithm and check for negative cycles
    if (bellmanFord(vertices, edges, edgeList, source, destination)) {
        cout << "No negative weight cycle detected.\n";
    } else {
        cout << "Negative weight cycle detected!\n";
    }

    return 0;
}
