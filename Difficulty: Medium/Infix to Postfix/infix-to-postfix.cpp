//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    int priority(char ch) {
        if (ch == '^') return 3; // Higher precedence for '^' (right-associative)
        else if (ch == '*' || ch == '/') return 2;
        else if (ch == '+' || ch == '-') return 1;
        return -1; // Invalid or non-operator
    }

    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string& s) {
        stack<char> st;  // Stack to hold operators and parentheses
        string ans = ""; // Resultant postfix expression

        for (char ch : s) {
            if (isalnum(ch)) {
                // If the character is an operand (letter or digit), add it to the result
                ans += ch;
            } else if (ch == '(') {
                // Push '(' onto the stack
                st.push(ch);
            } else if (ch == ')') {
                // Pop from the stack until '(' is encountered
                while (!st.empty() && st.top() != '(') {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop(); // Remove '('
            } else {
                // Operator encountered
                while (!st.empty() && priority(ch) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }

        // Pop all remaining operators in the stack
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};



//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends