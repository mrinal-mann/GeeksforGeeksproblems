//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int q, vector<int> &in){
       vector<int> ans(q,0);
       
       vector<int> NGE_cnt(n,0);
       
       stack<int> st;
       for(int i = n-1 ; i>=0 ; i-- ){
            if(st.empty()){
                st.push(arr[i]);
            }else{
                vector<int> temp;
                int cnt = 0;
                while(!st.empty() && st.top() > arr[i]){
                    temp.push_back(st.top());
                    st.pop();
                    cnt++;
                }
                NGE_cnt[i] = cnt;
                st.push(arr[i]);
                int m = temp.size();
                for(int j = m-1;j>=0;j--){
                    st.push(temp[j]);
                }
            }
       }
       for(int i  =0 ;i < q ; i++){
           ans[i] = NGE_cnt[in[i]];
       }
       return ans;
       
    }

};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> v1(n);
       for(int i = 0;i<n;i++) cin >> v1[i];
        int q; cin >> q;
        vector<int> v2(q);
        for(int i = 0;i<q;i++) cin >> v2[i];

        Solution obj;
        vector<int> ans = obj.count_NGE(n,v1,q,v2);

        for(int i = 0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends