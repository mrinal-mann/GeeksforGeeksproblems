//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
#include <bits/stdc++.h>
class Solution {
  public:
    // Helper function to recursively calculate subset sums
    void helper(vector<int>& arr, int index, int sum, vector<int>& result) {
        // Base condition: If we've processed all elements
        if (index == arr.size()) {
            result.push_back(sum); // Add the computed sum to the result
            return;
        }
        // Recursive case 1: Include the current element in the subset
        helper(arr, index + 1, sum + arr[index], result);
        // Recursive case 2: Exclude the current element from the subset
        helper(arr, index + 1, sum, result);
    }

    // Main function to compute all subset sums
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> result; // Stores all subset sums
        helper(arr, 0, 0, result); // Start recursion with sum = 0 and index = 0
        sort(result.begin(), result.end()); // Sort the result for ascending order
        return result; // Return the sorted list of subset sums
    }
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string inputLine;

        // Input format: first number n followed by the array elements
        getline(cin, inputLine);
        stringstream inputStream(inputLine);
        int num;
        while (inputStream >> num) {
            inputArray.push_back(num); // Read the array elements from input string
        }

        Solution solutionObject;
        vector<int> result = solutionObject.subsetSums(inputArray);
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout
            << endl
            << "~\n"; // Print results in list format with new line after each test case
    }

    return 0;
}

// } Driver Code Ends
