//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s) {
     // Reverse the entire equation string
    reverse(s.begin(), s.end());
    
    // Reverse each individual number in the equation
    int start = 0;
    int end = 0;
    while (end < s.length()) {
        if (s[end] == '+' || s[end] == '-' || s[end] == '*' || s[end] == '/') {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
        end++;
    }
    
    // Reverse the last number in the equation
    reverse(s.begin() + start, s.end());
    
    return s;
     }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends