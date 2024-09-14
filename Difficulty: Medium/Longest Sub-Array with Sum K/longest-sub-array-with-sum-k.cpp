//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int lenOfLongSubarr(int A[], int N, int K) {
        map<long long, int> preSum; // To store prefix sum and its index
        long long sum = 0; // To keep track of the prefix sum
        int maxlen = 0; // To keep track of the maximum length of subarray

        for (int i = 0; i < N; i++) {
            sum += A[i]; // Update the prefix sum

            // If the prefix sum equals K, update the maximum length
            if (sum == K) {
                maxlen = max(maxlen, i + 1);
            }

            // Calculate the remaining sum needed to reach K using reverse mathematics
            long long rem = sum - K;

            // If the remaining sum is found in the map, update the maximum length
            if (preSum.find(rem) != preSum.end()) {
                int len = i - preSum[rem];
                maxlen = max(maxlen, len);
            }

            // If the prefix sum is not already in the map, add it
            if (preSum.find(sum) == preSum.end()) {
                preSum[sum] = i;
            }
        }

        return maxlen; // Return the maximum length found
    }
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends