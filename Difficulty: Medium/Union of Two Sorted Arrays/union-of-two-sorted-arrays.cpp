//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        int i=0;
        int j=0;
        vector<int>unionarr;
        while(i<n && j<m){
            if(arr1[i]<=arr2[j]){
                if(unionarr.size()==0 ||   //if the array has 1 element that is the 1st element
                unionarr.back()!=arr1[i]){ //check the union array last element is equal to the current element
                    unionarr.push_back(arr1[i]);
                }
                i++;
            }else{
                if(unionarr.size()==0 || 
                unionarr.back()!=arr2[j]){
                    unionarr.push_back(arr2[j]);
                }
                j++;
            }
        }
        
        //if one of the array is exausted then it check on the remaining elements
        while(j<m){
            if(unionarr.size()==0 || 
                unionarr.back()!=arr2[j]){
                    unionarr.push_back(arr2[j]);
                }
            j++;
        }
        
        while(i<n){
            if(unionarr.size()==0 ||   
                unionarr.back()!=arr1[i]){ 
                    unionarr.push_back(arr1[i]);
                }
            i++;
        }
        return unionarr;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends