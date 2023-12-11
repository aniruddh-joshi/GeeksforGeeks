//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr(string S1, string S2, int n, int m) {
    // your code here
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0; // Variable to store the length of the longest common substring

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (S1[j - 1] == S2[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]); // Update maxLength if a longer common substring is found
            } else {
                dp[i][j] = 0; // If characters do not match, reset the length of common substring
            }
        }
    }

    return maxLength;
}

};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends