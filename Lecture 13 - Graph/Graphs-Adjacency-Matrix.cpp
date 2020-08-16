#include <bits/stdc++.h>
using namespace std;

// Initialize an adjacency Matrix with static length
const int N = 1e3+3;
int n;
bool adj[N][N];

// This function adds edges between given vertices (undirected edge)
void add_edge(int u, int v) {
    adj[u][v] = true;
    adj[v][u] = true;
}

// Initialize an array to mark visited vertices
bool vis_bfs[N];

// This function traverses the graph in breadth first search
void bfs(int src) {
    queue<int> q;
    // push and mark the source node as visited
    q.push(src);
    vis_bfs[src] = true;
	// loop to print all vertices in the graph
    while (!q.empty()) {
        int u = q.front();
        // pop and print the front node
        q.pop();
        cout << u << ' ';
        for (int v = 1 ; v <= n ; v++) {
            if(adj[u][v] && vis_bfs[v] == false) {
                // push and mark the current node as visited
                q.push(v);
                vis_bfs[v] = true;
            }
        }
    }
}

// Initialize an array to mark visited vertices
bool vis_dfs[N];

// This function traverses the graph in depth first search
void dfs(int src) {
    stack<int> stk;
    // push and mark the source node as visited
    stk.push(src);
    vis_dfs[src] = true;
	// loop to print all vertices in the graph
    while (!stk.empty()) {
        int u = stk.top();
        // pop and print the top node
        stk.pop();
        cout << u << ' ';
		// loop for all neighbors of the vertex u
        for (int v = 1; v <= n; v++) {
            if(adj[u][v] && vis_dfs[v] == false) {
				// push and mark the source node as visited
                stk.push(v);
                vis_dfs[v] = true;
            }
        }
    }
}

// Initialize an array to mark visited vertices
bool vis[N];

// This function traverses the graph in depth first search
void dfs_util(int u) {
    // mark the current node as visited and print it
    vis[u] = true;
    cout << u << ' ';
    // recursive for all the vertices adjacent to this vertex
    for (int v = 1 ; v <= n ; v++) {
        // check if this vertex not visited yet
        if(adj[u][v] && vis[v] == false)
            dfs_util(v);
    }
}

// This function traverses the graph in depth first search
void dfs() {
    // Call the recursive helper function to print dfs traversal
    // starting from all vertices one by one
    for (int i = 1 ; i <= n ; i++)
        // check if this vertex not visited yet
        if (vis[i] == false)
            dfs_util(i);
}

int main() {

	// Testing operators functionality

    n = 5;
    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(2, 4);
    add_edge(5, 3);
    add_edge(2, 3);
    add_edge(1, 5);
    
    cout << "Graph representation in bfs : \n";
    bfs(1);
    cout << "\n----------------------------------------------------\n";
    cout << "Graph representation in dfs iterative : \n";
    dfs(1);
    cout << "\n----------------------------------------------------\n";
    cout << "Graph representation in dfs recursion : \n";
    dfs();
    cout << "\n----------------------------------------------------\n";

	/* Expected Output:
	Graph representation in bfs : 
	1 2 3 5 4 
	----------------------------------------------------
	Graph representation in dfs iterative : 
	1 5 3 2 4 
	----------------------------------------------------
	Graph representation in dfs recursion : 
	1 2 4 3 5 
	----------------------------------------------------
	*/

}

