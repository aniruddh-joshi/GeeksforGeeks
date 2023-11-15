//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int count(string str) {
        unordered_map<char,int>mp;
        int n = str.size();
        int dp[n+1];
        dp[0] = 1;
        for(int i=1;i<=n;i++) {
            dp[i] = 2* dp[i-1];
            if(mp.find(str[i-1])!=mp.end()) {
                dp[i] = dp[i]-dp[mp[str[i-1]]];
            }
            mp[str[i-1]] = i-1;
        }
        return dp[n];
    }
    string betterString(string str1, string str2) {
        // code here
        int first = count(str1);
        int second = count(str2);
        if(first<second) return str2;
        else return str1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends