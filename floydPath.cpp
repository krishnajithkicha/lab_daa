#include <iostream>
using namespace std;

#define INF 99999  // Define a large value to represent infinity (no direct connection)

// Function to print the path from source to destination
void printPath(int predecessor[][100], int i, int j) {
    if (i == j) {
        cout << i << " "; // Path starts at the source
        return;
    }
    if (predecessor[i][j] == -1) {
        cout << "No path"; // No path exists
        return;
    }
    printPath(predecessor, i, predecessor[i][j]); // Recursive call to trace the path
    cout << j << " "; // Append the current vertex to the path
}

void floydWarshall(int graph[][100], int n) {
    int dist[100][100];
    int predecessor[100][100]; // To store the path information

    // Initialize distance and predecessor matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];

            // Predecessor is -1 if no edge exists, otherwise it's the source vertex
            if (graph[i][j] == INF || i == j) {
                predecessor[i][j] = -1; // No predecessor for no edge or self-loops
            } else {
                predecessor[i][j] = i; // Direct edge means predecessor is the source vertex
            }
        }
    }

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {          // Pick intermediate vertex k
        for (int i = 0; i < n; i++) {      // Pick source vertex
            for (int j = 0; j < n; j++) {  // Pick destination vertex
                // Update the distance if the path through k is shorter
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    predecessor[i][j] = predecessor[k][j]; // Update the predecessor
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "\nShortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    // Print the paths
    cout << "\nShortest paths between every pair of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Path from " << i << " to " << j << ": ";
            if (dist[i][j] == INF) {
                cout << "No path\n";
            } else {
                printPath(predecessor, i, j);
                cout << endl;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    int graph[100][100];
    cout << "Enter the adjacency matrix (use " << INF << " for infinity):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, n);

    return 0;
}
