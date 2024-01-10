//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

int longestSubstrDistinctChars(string S) {
    unordered_map<char, int> mp;
    int sol = 0;
    int i = 0;

    for (int j = 0; j < S.size(); ++j) {
        mp[S[j]]++;
        while (mp[S[j]] > 1) {
            mp[S[i++]]--;
        }
        sol = max(sol, j - i + 1);
    }

    return sol;
}
