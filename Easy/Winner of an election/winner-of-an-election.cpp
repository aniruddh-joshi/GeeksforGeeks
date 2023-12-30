//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
    vector<string> winner(string arr[],int n) {
        unordered_map<string,int>m;
        int mx=0;
        for(int i=0;i<n;i++){
            m[arr[i]]+=1;
            mx=max(mx,m[arr[i]]);
        }
        vector<string>p;
        for(auto a:m){
            if(mx==a.second)
            p.push_back(a.first);
        }
        sort(p.begin(),p.end());
        return {p[0],to_string(mx)};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends