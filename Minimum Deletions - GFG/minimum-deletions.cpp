//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
  public:
    int dp[1001][1001];
    int fun(int i,int j, string &a,string &b){
        if(i==a.size() || j==a.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(a[i]==b[j]){
            ans=max(ans,1+fun(i+1,j+1,a,b)); 
        }
        ans=max({ans,fun(i+1,j,a,b),fun(i,j+1,a,b)});
        return dp[i][j]=ans;
    }
    
    int minimumNumberOfDeletions(string s) {
        memset(dp,-1,sizeof(dp));
        string t=s;
        reverse(s.begin(),s.end());
        return s.size()-fun(0,0,s,t); 
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends