//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends
//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x) {
     int sl= s.length();
     int xl= x.length();
     
     for(int i=0;i<=sl-xl;i++) {
         if(s.substr(i,xl)==x) {
             return i;
         }
     }
     return -1;
}