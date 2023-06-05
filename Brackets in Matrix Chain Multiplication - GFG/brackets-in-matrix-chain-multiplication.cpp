//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
     pair<int, string> helper(int arr[], int i, int j, vector<vector<pair<int , string>>> &dp)
{
    if (i == j)
    {
        string st = "";
        st += 'A' + i - 1;
        return {0, st};
    }
    if(dp[i][j].first!=-1){
         return dp[i][j];
    }
    int ans = INT_MAX;
    string st = "";
    for (int k = i; k <= j - 1; k++)
    {
        pair<int, string> p = helper(arr, i, k ,dp);
        pair<int, string> q = helper(arr, k + 1, j ,dp);
        int a = p.first + q.first + arr[i - 1] * arr[k] * arr[j];
        string str = "(" + p.second + q.second + ")";
        if (a < ans)
        {
            ans = a;
            st = str;
        }
    }
    return dp[i][j]={ans, st};
}

string matrixChainOrder(int arr[], int n)
{
    // code here
    vector<vector<pair<int , string>>>dp(n,vector<pair<int , string>>(n,{-1,""}));
    pair<int, string> p;
    p = helper(arr, 1, n - 1,dp);
    return p.second;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends