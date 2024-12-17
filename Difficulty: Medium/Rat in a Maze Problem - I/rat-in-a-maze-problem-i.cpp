//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Helper function to recursively explore all possible paths
    void helper(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, 
                string move, vector<vector<int>> &vis, int di[], int dj[]) {
        // Base condition: If the destination cell (n-1, n-1) is reached
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);  // Store the current path
            return;
        }
        
        // String to represent the direction movement: Down, Left, Right, Up
        string dir = "DLRU";
        
        // Iterate over all 4 possible directions
        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind]; // Next row
            int nextj = j + dj[ind]; // Next column
            
            // Check if the next position is within bounds, not visited, and valid (mat[nexti][nextj] == 1)
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n 
                && !vis[nexti][nextj] && mat[nexti][nextj] == 1) {
                
                vis[i][j] = 1;  // Mark the current cell as visited
                
                // Recursive call to move to the next cell, appending the corresponding direction
                helper(nexti, nextj, mat, n, ans, move + dir[ind], vis, di, dj);
                
                vis[i][j] = 0;  // Backtrack: unmark the current cell
            }
        }
    }
    
    // Main function to find all paths in the maze
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();  // Dimension of the maze
        vector<vector<int>> vis(n, vector<int>(n, 0));  // Visited matrix initialized to 0
        vector<string> ans;  // Vector to store all possible paths
        
        // Movement arrays for Down, Left, Right, and Up directions
        int di[] = {1, 0, 0, -1};  // Row increments: D, L, R, U
        int dj[] = {0, -1, 1, 0};  // Column increments: D, L, R, U
        
        // Check if the start position (0, 0) is valid
        if (mat[0][0] == 1) {
            helper(0, 0, mat, n, ans, "", vis, di, dj);  // Start recursion from (0, 0)
        }
        
        return ans;  // Return all valid paths
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends