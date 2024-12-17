//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void helper(vector<vector<int>> &mat, int i, int j, string path, vector<string> &ans, int n) {
        // Base case: If we reach the bottom-right cell, add the path to the answer
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }
        
        // Mark the cell as visited
        mat[i][j] = 0;

        // Move Down
        if (i + 1 < n && mat[i + 1][j] == 1) {
            helper(mat, i + 1, j, path + 'D', ans, n);
        }

        // Move Right
        if (j + 1 < n && mat[i][j + 1] == 1) {
            helper(mat, i, j + 1, path + 'R', ans, n);
        }

        // Move Up (if needed)
        if (i - 1 >= 0 && mat[i - 1][j] == 1) {
            helper(mat, i - 1, j, path + 'U', ans, n);
        }

        // Move Left (if needed)
        if (j - 1 >= 0 && mat[i][j - 1] == 1) {
            helper(mat, i, j - 1, path + 'L', ans, n);
        }

        // Backtrack: Unmark the cell
        mat[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> ans;
        
        // Check if the starting cell is walkable
        if (mat[0][0] == 1) {
            helper(mat, 0, 0, "", ans, n);
        }
        
        return ans;
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