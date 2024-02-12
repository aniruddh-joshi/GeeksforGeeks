//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    long long sequence(int n){
        // code here
        long long int mod = pow(10.0,9.0)+7.0;
        long long int ans=0;
        int j = 1;
        for(int i = 1; i <=n; i++){
            long long int temp = 1;
            for( int count=0 ;count< i;j++,count++ ){
            temp*=j;
            temp%=mod;
            }
            ans+=temp%mod;
        }
        return ans%mod;
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
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends