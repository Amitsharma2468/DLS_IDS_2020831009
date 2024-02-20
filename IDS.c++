//2020831009
#include <bits/stdc++.h>

using namespace std;

// Function to perform Depth First Search (DFS)
bool DFS(int start, int target, vector<vector<int>>& graph) {
    stack<int> st;
    vector<bool> visited(graph.size(), false);

    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int current = st.top();
        st.pop();

        if (current == target) {
            return true;
        }

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false;
}

// perform Iterative Deepening Search (IDS)
bool IDS(int start, int target, vector<vector<int>>& graph) {
    int maxDepth = graph.size(); // Max depth 

    for (int depth = 0; depth <= maxDepth; depth++) {
        stack<int> st;
        vector<bool> visited(graph.size(), false);

        st.push(start);
        visited[start] = true;

        while (!st.empty()) {
            int current = st.top();
            st.pop();

            if (current == target) {
                return true;
            }

            if (depth > 0) {
                //  if the current depth is in the limit
                if (depth >= st.size()) {
                    continue;
                }
            }

            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    st.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    return false;
}

int main() {
    // Example usage
    vector<vector<int>> graph = {
        {1, 2},     // Node 0 is connected to nodes 1 and 2
        {3, 4},     // Node 1 is connected to nodes 3 and 4
        {5},        // Node 2 is connected to node 5
        {6, 7},     // Node 3 is connected to nodes 6 and 7
        {8},        // Node 4 is connected to node 8
        {9},        // Node 5 is connected to node 9
        {},         // Node 6 has no connections
        {},         // Node 7 has no connections
        {},         // Node 8 has no connections
        {}          // Node 9 has no connections
    };

    int startNode = 0;
    int targetNode = 9;

    // Perform Depth First Search (DFS)
    bool dfsResult = DFS(startNode, targetNode, graph);
    cout << "DFS Result: " << (dfsResult ? "Found" : "Not Found") << endl;

    // Perform Iterative Deepening Search (IDS)
    bool idsResult = IDS(startNode, targetNode, graph);
    cout << "IDS Result: " << (idsResult ? "Found" : "Not Found") << endl;

    return 0;
}
