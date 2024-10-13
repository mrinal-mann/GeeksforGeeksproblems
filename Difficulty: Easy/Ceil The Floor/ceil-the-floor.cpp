//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
       int f = -1;
       int c = -1;
       bool flag=false;
       int n=arr.size();
       int ans=INT_MAX;
        for(int i = 0; i < n; i++) {
            if(arr[i] <= x) {
                f=max(arr[i],f);
            } 
            if(arr[i]>=x){
                flag=true;
                ans=min(arr[i],ans);
            }
        }
        if(flag==true){
            c=ans;
        }
        return {f,c}; // Return j as the index of the floor, or -1 if no floor found
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends