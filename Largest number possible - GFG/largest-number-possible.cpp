//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        if(S==0 && N>1)     return "-1";
        if(S==0 && N==1)     return "0";
        string ans="";
        int i=9;
        while(ans.size()!=N){
            if(S>=i){
                S-=i;
                ans+=to_string(i);
            }
            else
            i--;
        }
        if(S==0)
            return ans;
        else
            return "-1";
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends