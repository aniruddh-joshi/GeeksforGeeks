//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // Function to find the length of the longest common subsequence in two strings.
    int lcs(int m, int n, string s1, string s2)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }

    // Function to find the length of the longest palindromic subsequence.
    int longestPalinSubseq(string A)
    {
        string B = A; // Create a copy of the original string.
        reverse(B.begin(), B.end()); // Reverse the copy.

        // Use the LCS function to find the length of the longest palindromic subsequence.
        return lcs(A.length(), B.length(), A, B);
    }
};


//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends