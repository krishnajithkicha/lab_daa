#include <iostream>
#include <queue>
using namespace std;

int adj[10][10];      // Adjacency matrix
int visited[10];      // Visited array
int predecessor[10];  // Predecessor array
int n;                // Number of vertices

// BFS function
void BFS(int start) {
    queue<int> Q;

    Q.push(start);
    visited[start] = 1;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        cout << "Visited: " << u << endl;
        
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                predecessor[v] = u;
                Q.push(v);
            }
        }
    }
    for (int i = 0; i < n; i++) {  // Visit vertices with no predecessor
        if (visited[i] != 1) {
            BFS(i);
        }
    }
}
// DFS function
void DFS(int u) {
    cout << "Visited: " << u << endl;
    visited[u] = 1; // Mark the current vertex as visited
    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && visited[v] == 0) { // If there's an edge and v is not visited
            predecessor[v] = u; // Set the predecessor of v
            DFS(v); // Recursive call to visit the connected vertex
        }
    }
    for (int i = 0; i < n; i++) {  // Visit vertices with no predecessor
        if (visited[i] != 1) {
            DFS(i);
        }
    }
}
void clear(){
	fill(visited, visited + n, 0); // Reset visited array for BFS
    fill(predecessor, predecessor + n, -1); // Reset predecessor array for BFS
}


int main() {
    cout << "Enter the number of vertices: ";
    cin >> n; // Assign number of vertices to global variable n

    // Initialize adjacency matrix, visited array, and predecessor array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0; // No edges initially
        }
        visited[i] = 0;      // Not visited initially
        predecessor[i] = -1; // No predecessor initially
    }

    int edges, u, w;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the edges (u w):" << endl;
    for (int i = 0; i < edges; i++) {
        cin >> u >> w;
        adj[u][w] = 1; // Mark edge in adjacency matrix
    }

    // Perform DFS starting from vertex 0
    cout<<"Enter start vertex:";
    int st;
    cin>>st;
    cout << "Depth-First Search starting from vertex :"<<st << endl;
    DFS(st);

    // Print the predecessor array
    cout << "Predecessor array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ":";
        if (predecessor[i] == -1) {
            cout << " Predecessor: NIL" << endl;
        } else {
            cout << " Predecessor: " << predecessor[i] << endl;
        }
    }
	clear();
	    cout<<"Enter start vertex:";
    int s;
    cin>>s;
    // Perform BFS starting from vertex 0
    cout << "Breadth-First Search starting from vertex :"<<s<< endl;
    BFS(s);
        // Print the predecessor array
    cout << "Predecessor array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ":";
        if (predecessor[i] == -1) {
            cout << " Predecessor: NIL" << endl;
        } else {
            cout << " Predecessor: " << predecessor[i] << endl;
        }
    }
    return 0;
}

