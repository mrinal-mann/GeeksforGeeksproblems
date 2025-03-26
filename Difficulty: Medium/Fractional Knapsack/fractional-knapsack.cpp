//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
public:
    // Comparator function to sort items by value-to-weight ratio in descending order
    static bool comp(pair<double, int> a, pair<double, int> b) {
        return a.first > b.first;  // Sort by highest value-to-weight ratio
    }

    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double, int>> items; // Stores (value/weight ratio, index)

        // Compute value-to-weight ratio for each item
        for (int i = 0; i < n; i++) {
            items.push_back({(double)val[i] / wt[i], i});
        }

        // Sort items based on value-to-weight ratio in descending order
        sort(items.begin(), items.end(), comp);

        double totalValue = 0.0;
        int currentWeight = 0;

        // Process each item
        for (int i = 0; i < n; i++) {
            int idx = items[i].second;  // Get the original index of the item

            if (currentWeight + wt[idx] <= capacity) {
                // Take the whole item
                currentWeight += wt[idx];
                totalValue += val[idx];
            } else {
                // Take the fraction of the item that fits
                int remainingWeight = capacity - currentWeight;
                totalValue += items[i].first * remainingWeight; // value/weight * weight
                break; // Knapsack is full
            }
        }

        return totalValue;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends