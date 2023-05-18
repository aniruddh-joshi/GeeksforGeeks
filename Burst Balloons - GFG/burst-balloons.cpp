//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxCoins(int N, vector<int> &arr) {
        // code here
        arr.insert(arr.begin(),1);
        arr.insert(arr.end(),1);
        vector<vector<int>>dp(N+2,vector<int>(N+2));
        for(int len=1;len<=N;len++){
            for(int i=1;i+len-1<=N;i++){
                int j=i+len-1;
                for(int k=i;k<=j;k++){
                    dp[i][j]=max(dp[i][j],dp[i][k-1]+arr[i-1]*arr[k]*arr[j+1]+dp[k+1][j]);
                }
            }
        }
        return dp[1][N];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends