//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void rec(int n, int i,int one, int zero,vector<string> &ans, string temp)
    {
        if(i>=n)
        {
            ans.push_back(temp);
            return;
        }
        temp += '1';
        rec(n,i+1,one+1,zero,ans,temp);
        temp.pop_back();
        if(one > zero)
        {
            temp += '0';
            rec(n,i+1,one,zero+1,ans,temp);
            temp.pop_back();
        }
    }
	vector<string> NBitBinary(int n)
	{
	    vector<string> ans;
	    rec(n,0,0,0,ans,"");
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends