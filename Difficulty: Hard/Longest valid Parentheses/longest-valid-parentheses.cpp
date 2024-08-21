//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    int maxLength(std::string S) {
        std::stack<int> stk;
        stk.push(-1); // Initialize stack with -1 to handle the base case
        int maxLength = 0;

        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '(') {
                stk.push(i); // Push the index of '('
            } else {
                stk.pop(); // Pop the last index

                if (stk.empty()) {
                    stk.push(i); // Push current index if stack is empty
                } else {
                    // Calculate the length of the current valid substring
                    maxLength = std::max(maxLength, i - stk.top());
                }
            }
        }

        return maxLength;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends