//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        const ll MOD = 1000000007;
         vector<vector<ll>>ans;

        for(int i=0;i<n;i++){
            vector<ll>row(i+1,1);
            for(int j=1;j<i;j++){
                row[j]=(ans[i-1][j]+ans[i-1][j-1])%MOD;
            }
            ans.push_back(row);
        }
        return ans[n-1];
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends