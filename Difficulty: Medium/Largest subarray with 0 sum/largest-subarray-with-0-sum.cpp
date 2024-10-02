//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution {
  public:
    int maxLen(vector<int>& arr, int n) {
        map<long long,int> mpp;
        long long sum=0;
        int maxL=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0){
                maxL=max(maxL,i+1);
            }
            long long rem=sum-0;
            if(mpp.find(rem)!=mpp.end()){
                int len=i-mpp[rem];
                maxL=max(maxL,len);
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
            
        }
        return maxL;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i) {
            cin >> array1[i];
        }
        Solution ob;
        cout << ob.maxLen(array1, m) << endl;
    }
    return 0;
}

// } Driver Code Ends