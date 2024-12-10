#include <iostream>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int u, v, weight;
};

// Function to find the parent of a vertex (using union-find)
int findSet(int parent[], int v) {
    if (parent[v] == v)
        return v;
    return findSet(parent, parent[v]);
}

// Function to perform union of two sets
void unionSet(int parent[], int rank[], int u, int v) {
    int rootU = findSet(parent, u);
    int rootV = findSet(parent, v);

    if (rank[rootU] > rank[rootV]) {
        parent[rootV] = rootU;
    } else if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

// Comparison function to sort edges by weight
bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

void kruskal(Edge edges[], int V, int E) {
    // Array to store the parent of each vertex
    int parent[V];
    int rank[V]; // Rank array for union by rank
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort edges by weight
    sort(edges, edges + E, compareEdges);

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    int mstWeight = 0;

    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        // Check if including this edge creates a cycle
        if (findSet(parent, u) != findSet(parent, v)) {
            cout << u << " -- " << v << " == " << weight << endl;
            mstWeight += weight;
            unionSet(parent, rank, u, v);
        }
    }

    cout << "Total weight of Minimum Spanning Tree: " << mstWeight << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Edge edges[E];
    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskal(edges, V, E);

    return 0;
}
