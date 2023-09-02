//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long countSubarray(int n,vector<int> arr,int m) {
        return fun(n,arr,m)-fun(n,arr,m+1);
    }
    
    long long fun(int n,vector<int> arr,int m){
        unordered_map<int,int> mp;
        mp[0]++;
        int sum=0;
        long long ans=0,currElement=0;
        for(int i=0;i<n;i++){
            if(arr[i]<m){
                sum--;
                currElement-=mp[sum];
            }
            else{
                currElement+=mp[sum];
                sum++;
            }
            ans+=currElement;
            mp[sum]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin>>N>>M;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,M);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends