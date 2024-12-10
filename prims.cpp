#include <iostream>
#include <climits>
using namespace std;



// Function to find the vertex with the minimum key value
int extractMin(int key[], bool inMST[], int nodes) {
    int minKey = INT_MAX, minIndex = -1;

    for (int i = 0; i < nodes; i++) {
        if (!inMST[i] && key[i] < minKey) {
            minKey = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void primMST(int graph[100][100], int nodes) {
    int parent[100];  // Array to store the MST
    int key[100];     // Key values to pick minimum weight edge
    bool inMST[100];  // To represent vertices included in MST

    // Step 1: Initialize all keys to infinity and inMST to false
    for (int i = 0; i < nodes; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

    // Step 2: Start with the first node (arbitrary root)
    key[0] = 0;       // Key of the root node is 0
    parent[0] = -1;   // Root node has no parent

    // Step 3: Loop to construct the MST
    for (int count = 0; count < nodes - 1; count++) {
        // Pick the minimum key vertex not yet included in MST
        int u = extractMin(key, inMST, nodes);

        // Include the vertex in MST
        inMST[u] = true;

        // Update the key and parent of adjacent vertices
        for (int v = 0; v < nodes; v++) {
            // If the edge exists, and vertex v is not in MST,
            // and the weight is smaller than the current key
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Step 4: Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < nodes; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
    }
}

int main() {
    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    int graph[100][100];

    cout << "Enter the adjacency matrix of the graph (use 0 for no edge):\n";
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(graph, nodes);

    return 0;
}
