//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long handShakes(int N){
        // code here
        long long ans=((long long)N * (N - 1)) / 2;
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
        cout<<ob.handShakes(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends