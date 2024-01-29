//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int dp[100][901];
class Solution{
    int solve(string &s, int i, int prev) {
        if(i == s.size())
            return 1;
        
        if(dp[i][prev] != -1)
            return dp[i][prev];
        
        int cur = 0;
        int ans = 0;
        for(int j = i; j < s.size(); j++) {
            cur += (s[j] - '0');
            if(cur >= prev)
                ans += solve(s, j + 1, cur);
        }
        return dp[i][prev] = ans;
    }
	public:
	int TotalCount(string str){
	    memset(dp, -1, sizeof dp);
	    return solve(str, 0, 0);
	}
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends