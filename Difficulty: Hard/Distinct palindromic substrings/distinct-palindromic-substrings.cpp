//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        int n = s.length();
        set<string> palindromes;

        // Odd length palindromes
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                palindromes.insert(s.substr(l, r - l + 1)); // Add the palindrome to the set
                l--;
                r++;
            }
        }

        // Even length palindromes
        for (int i = 0; i < n; i++) {
            int l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                palindromes.insert(s.substr(l, r - l + 1)); // Add the palindrome to the set
                l--;
                r++;
            }
        }

        return palindromes.size(); // Return the number of distinct palindromes
    }
};


//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}

// } Driver Code Ends