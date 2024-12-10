#include <iostream>
using namespace std;

#define INF 99999  // Define a large value to represent infinity (no direct connection)

void floydWarshall(int graph[][100], int n) {
    int dist[100][100];

    // Initialize the solution matrix same as the input graph matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {          // Pick intermediate vertex k
        for (int i = 0; i < n; i++) {      // Pick source vertex
            for (int j = 0; j < n; j++) {  // Pick destination vertex
                // Update the distance if the path through k is shorter
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the resulting shortest path matrix
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
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
