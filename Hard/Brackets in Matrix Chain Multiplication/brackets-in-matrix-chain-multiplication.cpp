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

int get(int p[],int n)
{
    int m[n][n],ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n-L+1; i++){ 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                { 
                    m[i][i + L - 1] = q;
                }
            }
        }
    }
    return m[1][n-1];
}

int find(string s,int p[])
{
    vector<pair<int,int>> arr;
    int ans = 0;
    for(auto t:s)
    {
        if(t=='(')
        {
            arr.push_back({-1,-1});
        }
        else if(t==')')
        {
            pair<int,int> b=arr.back();
            arr.pop_back();
            pair<int,int> a=arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first,b.second});
            ans += a.first*a.second*b.second;
        }
        else 
        {
            arr.push_back({p[int(t-'A')],p[int(t-'A')+1]});
        }
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
        {
            cin>>p[i];
        }
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result,p)==get(p,n))
        {
            cout<<"True"<<endl;
        }
        else
        {
            cout<<"False"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends