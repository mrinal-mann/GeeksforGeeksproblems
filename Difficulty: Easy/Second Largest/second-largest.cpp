//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int print2largest(vector<int> &arr) {
        int largest=arr[0];
        int secondlargest=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>largest && arr[i]>secondlargest){
                secondlargest=largest;
                largest=arr[i];
                
            }
            else if(arr[i]<largest && arr[i]>secondlargest){
              secondlargest=arr[i];  
            }
        }
        return secondlargest;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends