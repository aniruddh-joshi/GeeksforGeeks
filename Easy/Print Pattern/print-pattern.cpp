//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    void solve(vector<int> &ans, int n) {
        if(n <= 0) {
            ans.push_back(n);
            return;
        }
        ans.push_back(n);
        solve(ans, n-5);
        ans.push_back(n);
    }
    
    vector<int> pattern(int n){
        vector<int> ans;
        solve(ans, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends