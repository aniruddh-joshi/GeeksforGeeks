//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    using ll = long long;
    ll m = 1e9 + 7;
    
    ll pow(ll a, int n){
        if(n == 1)
            return a;
        ll b = pow(a, n/2);
        if(n%2)
            return (b*b*a)%m;
        else
            return (b*b)%m;
    }
    
    vector<vector<ll>> multi(vector<vector<ll>>& a, vector<vector<ll>>& b){
        vector<vector<ll>> t(2, vector<ll>(2,0));
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0; k<2;k++){
                    t[i][j] = (t[i][j] + a[i][k]*b[k][j])%m;
                }
            }
        }
        return t;
    }
    
    ll fib(int n){
        if(n == 1)
            return 2;
        if(n == 2)
            return 3;
        n = n-2;
        vector<vector<ll>> k = {{1,1}, {1,0}};
        vector<vector<ll>> f = {{3,0}, {2,0}};
        while(n){
            if(n&1)
                f = multi(k, f);
            k = multi(k, k);
            n = n>>1;
        }
        return (f[0][0])%m;
    }
    
    int numberOfConsecutiveOnes(int n) {
        // code here
        return (pow(2, n) + m - fib(n))%m;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends