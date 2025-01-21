//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> umap; // Stores the frequency of fruits
        int maxFruitCount = 0;
        int low = 0; // Left pointer of the sliding window

        for (int high = 0; high < n; ++high) {
            umap[arr[high]]++; // Add the current fruit to the basket

            // Shrink the window if there are more than 2 types of fruits
            while (umap.size() > 2) {
                umap[arr[low]]--; // Remove one fruit of type arr[low]
                if (umap[arr[low]] == 0) {
                    umap.erase(arr[low]); // Remove the fruit type if count becomes 0
                }
                low++; // Move the left pointer
            }

            // Update the maximum fruit count
            maxFruitCount = max(maxFruitCount, high - low + 1);
        }

        return maxFruitCount;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalElements(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends