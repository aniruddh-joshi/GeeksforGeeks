//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
    vector<int> recamanSequence(int n) {
        vector<int> a(n,0);
        set<int> s;
        s.insert(0);
        for(int i=1;i<n;i++) {
            a[i]=a[i-1]-i;
            if(a[i]<0 || s.find(a[i])!=s.end()) a[i]=a[i-1]+i;
            s.insert(a[i]);
        }
        return a;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends