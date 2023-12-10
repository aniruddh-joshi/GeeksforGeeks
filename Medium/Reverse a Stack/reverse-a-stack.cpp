//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void solve(stack<int>&St,int i,int n,int t){
        if(i==n){
            St.push(t);
            return;
        }
        int r=St.top();
        St.pop();
        solve(St,i+1,n,t);
        St.push(r);
    }
    void Reverse(stack<int> &St){
        if(St.empty())  return;
        int t=St.top();
        St.pop();
        Reverse(St);
        solve(St,0,St.size(),t);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends