//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        map<int,vector<int>> mp;
        mp[0]={0,8};
        mp[1]={1,2,4};
        mp[2]={1,2,3,5};
        mp[3]={2,3,6};
        mp[4]={1,4,5,7};
        mp[5]={2,4,5,6,8};
        mp[6]={3,5,6,9};
        mp[7]={4,7,8};
        mp[8]={5,7,8,9,0};
        mp[9]={6,8,9};
        
        long long dp[n+1][10]={0};
        for(int i=1;i<n+1;i++){
            for(int j=0;j<10;j++){
                if(i==1) dp[i][j]=1;
                else{
                    vector<int> temp=mp[j];
                    for(int k=0;k<temp.size();k++){
                        dp[i][j]+=dp[i-1][temp[k]];
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<10;i++){
            ans+=dp[n][i];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends