//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

// function to find longest common subsequence

class Solution
{
    public:
    
    int solve(string& a, string&b,int i,int j,vector<vector<int>>&dp){
        //base case
        if(i==a.length())    return 0;
        if(j==b.length())    return 0;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int ans=0;
        if(a[i]==b[j]){
            ans=1+solve(a,b,i+1,j+1,dp);
        }
        else{
            ans=max(solve(a,b,i+1,j,dp) , solve(a,b,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>>dp(x,vector<int>(y,-1));
        
        return solve(s1,s2,0,0,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends