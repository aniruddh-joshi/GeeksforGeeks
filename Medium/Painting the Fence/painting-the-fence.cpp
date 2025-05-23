//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution {
    public:
    const int mod = 1000000007;
    long long countWays(int n, int k) {
        vector<long long> dp(n + 1, 0);
        dp[1] = k;
        for(int i = 2; i <= n; i++) {
            dp[i] = ((dp[i - 1] + dp[i - 2]) * (k - 1)) % mod;
        }
        return (dp[n - 1] + dp[n]) % mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends