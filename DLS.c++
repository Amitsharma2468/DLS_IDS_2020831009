//2020831009
#include <bits/stdc++.h>

using namespace std;

// perform Depth-Limited Search
bool DLS(int node, int target, int depth, vector<vector<int>>& graph) {
    if (depth == 0 && node == target) {
        return true; // Target node found in the depth limit
    }
    if (depth > 0) {
        for (int neighbor : graph[node]) {
            if (DLS(neighbor, target, depth - 1, graph)) {
                return true; // Target node found in the subtree
            }
        }
    }
    return false; // Target node not found in the depth limit
}
 perform Depth-First Search
bool DFS(int start, int target, vector<vector<int>>& graph) {
    stack<int> stack;
    vector<bool> visited(graph.size(), false);

    stack.push(start);
    visited[start] = true;

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();

        if (node == target) {
            return true; // Target node found
        }

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                stack.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false; // Target node not found
}

int main() {
    // Example usage
    vector<vector<int>> graph = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {3, 4},     // Node 1 is connected to nodes 3 and 4
        {5},        // Node 2 is connected to node 5
        {6, 7},     // Node 3 is connected to nodes 6 and 7
        {8},        // Node 4 is connected to node 8
        {},         // Node 5 has no outgoing edges
        {},         // Node 6 has no outgoing edges
        {},         // Node 7 has no outgoing edges
        {}          // Node 8 has no outgoing edges
    };

    int startNode = 0;
    int targetNode = 8;
    int depthLimit = 3;

    // Perform Depth-Limited Search
    bool foundDLS = DLS(startNode, targetNode, depthLimit, graph);

    // Perform Depth-First Search
    bool foundDFS = DFS(startNode, targetNode, graph);

    cout << "Depth-Limited Search: " << (foundDLS ? "Target found" : "Target not found") << endl;
    cout << "Depth-First Search: " << (foundDFS ? "Target found" : "Target not found") << endl;

    return 0;
}
