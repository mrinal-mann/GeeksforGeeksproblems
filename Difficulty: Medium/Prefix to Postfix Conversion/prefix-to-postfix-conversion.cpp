//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string preToPost(string pre_exp) {
        int n = pre_exp.size();
        stack<string> st;

        // Iterate from right to left
        for (int i = n - 1; i >= 0; i--) {
            char ch = pre_exp[i];

            if (isalnum(ch)) {
                // If operand, push it to the stack
                st.push(string(1, ch));
            } else {
                // If operator, pop two operands from the stack
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();

                // Form the postfix expression
                string post_exp = op1 + op2 + ch;
                st.push(post_exp);
            }
        }

        // The final expression is at the top of the stack
        return st.top();
    }
};




//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends