//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          unordered_map<char,int>mp;
          for(int i=0;i<n;i++){
              mp[x[i]]=b[i];
          }
          int maxi=INT_MIN;
          int s=0;
          string temp="";
          string ans="";
          for(int i=0;i<w.size();i++){
              if(mp.find(w[i])!=mp.end()){
                  s+=mp[w[i]];
              }
              else{
                  s+=(int)w[i];
              }
              temp+=w[i];
              maxi=max(maxi,s);
              if(s==maxi)   ans=temp;
              if(s<0){
                  s=0;
                  temp="";
              }
          }
          return ans;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends