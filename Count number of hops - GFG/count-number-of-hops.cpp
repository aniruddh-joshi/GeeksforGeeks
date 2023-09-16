//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    long long countWays(int n) {
    vector<long long> dp(n+1);
       
       dp[0] = 1;
       dp[1] = 1;
       dp[2] = 2;
       
       for(int i=3;i<=n;i++) {
           dp[i] = dp[i-1] % 1000000007+ dp[i-2] % 1000000007+ dp[i-3] % 1000000007;
       }
       return dp[n] % 1000000007;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends