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
    string preToInfix(string pre_exp) {
        int i = pre_exp.size() - 1; // Start from the end of the prefix expression
        stack<string> st;

        while (i >= 0) {
            char ch = pre_exp[i];
            if (isalnum(ch)) {
                // If the character is an operand (letter or digit), push it to the stack
                st.push(string(1, ch));
            } else {
                // If the character is an operator, pop two operands from the stack
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                
                // Form the infix expression
                string con = "(" + t1 + ch + t2 + ")";
                st.push(con);
            }
            i--;
        }

        return st.top(); // The final infix expression is at the top of the stack
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
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends