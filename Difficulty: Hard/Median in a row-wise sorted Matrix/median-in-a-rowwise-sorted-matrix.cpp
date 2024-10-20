//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
#include <bits/stdc++.h>
class Solution{   
public:

    // Function to count the number of elements <= x in the matrix
    int countSmallEqual(vector<vector<int>> &matrix, int R, int C, int x) {
        int count = 0;
        for (int i = 0; i < R; i++) {
            // Use upper_bound to find the position of the first element > x in each row
            count += upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin();
        }
        return count;
    }

    // Function to find the median of the matrix
    int median(vector<vector<int>> &matrix, int R, int C) {
        int low = INT_MAX;
        int high = INT_MIN;

        // Finding the minimum and maximum element in the matrix
        for (int i = 0; i < R; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][C - 1]);
        }

        // We need (R * C) / 2 elements less than or equal to the median
        int req = (R * C) / 2;

        while (low <= high) {
            int mid = (low + high) / 2;
            int smallEqual = countSmallEqual(matrix, R, C, mid);

            if (smallEqual <= req) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends