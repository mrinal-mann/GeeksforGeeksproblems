//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Check if it's safe to color the current node with the given color
    bool isSafe(int node, int color[], vector<vector<int>>& adj, int col) {
        for (int neighbor = 0; neighbor < adj[node].size(); neighbor++) {
            if (adj[node][neighbor] == 1 && color[neighbor] == col) {
                return false;
            }
        }
        return true;
    }

    // Recursive function to solve graph coloring
    bool solve(int node, int color[], int m, int v, vector<vector<int>>& adj) {
        if (node == v) return true;
        
        // Try assigning colors from 1 to m
        for (int i = 1; i <= m; i++) {
            if (isSafe(node, color, adj, i)) {
                color[node] = i;
                if (solve(node + 1, color, m, v, adj)) return true;
                color[node] = 0;  // Backtrack
            }
        }
        return false;
    }

    // Main function to check if graph can be colored with at most m colors
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        // Create adjacency matrix
        vector<vector<int>> adj(v, vector<int>(v, 0));
        for (auto edge : edges) {
            adj[edge.first][edge.second] = 1;
            adj[edge.second][edge.first] = 1;
        }

        // Initialize color array to 0 (no color assigned)
        int color[v] = {0};

        // Start solving from node 0
        if (solve(0, color, m, v, adj)) return true;
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends