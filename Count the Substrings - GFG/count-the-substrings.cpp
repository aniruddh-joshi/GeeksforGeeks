//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        int n=S.length();
        int count=0;
        for(int i=0;i<n;i++){
            int lower=0,upper=0;
            for(int j=i;j<n;j++){
                if(isupper(S[j]))
                upper++;
                else if(islower(S[j]))
                lower++;
                if(upper==lower)    count++;
            }
        }
      return count; // code here
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends