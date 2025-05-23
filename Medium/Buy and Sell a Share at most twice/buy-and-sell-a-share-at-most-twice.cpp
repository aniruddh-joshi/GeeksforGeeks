//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        //User function Template for C++
        int fun(int i, int n, int curr, vector<int> &v, vector<vector<int>> &dp) {
            if(i==n || curr==4) return 0;
            if(dp[i][curr]!=-1) return dp[i][curr];
            
            int pick=0, notpick=0;
            if(curr%2==0) pick=-v[i]+ fun(i+1,n,curr+1,v,dp);
            if(curr%2==1) pick=v[i]+ fun(i+1,n,curr+1,v,dp);
            notpick= fun(i+1,n,curr,v,dp);
            
            return dp[i][curr] =max(pick,notpick);
        }
        
        int maxProfit(vector<int>&price){
            int n=price.size();
            vector<vector<int>> dp(n,vector <int> (4,-1));
            return fun(0,n,0,price,dp);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends