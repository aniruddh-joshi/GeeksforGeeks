//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    int solve(string& a, string&b,int i,int j,vector<vector<int>>&dp){
        //base case
        if(i==a.length())    return b.length()-j;
        if(j==b.length())    return a.length()-i;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int ans=0;
        if(a[i]==b[j]){
            ans=1+solve(a,b,i+1,j+1,dp);
        }
        else{
            ans=1+min(solve(a,b,i+1,j,dp) , solve(a,b,i,j+1,dp));
        }
        return dp[i][j]=ans;
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return solve(X,Y,0,0,dp);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends