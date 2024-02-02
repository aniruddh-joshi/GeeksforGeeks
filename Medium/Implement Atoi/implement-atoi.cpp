//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans=0;
        bool neg=false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='-' && i==0){
                neg=true;
            }
            else if(s[i]>=48 &&s[i]<58){
                ans=ans*10+(s[i]-48);
            }
            else
            return -1;
        }
        if(neg) return ans-(2*ans);
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends