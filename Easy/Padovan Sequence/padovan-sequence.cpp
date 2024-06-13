//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    const int MOD = 1000000007;
    int padovanSequence(int n)
    {
       //code here
    if (n <= 2)
    return 1;
    
    int a = 1, b = 1, c = 1;
    int result;
    for (int i = 3; i <= n; ++i) {
        result = (b + a) % MOD;
        a = b;
        b = c;
        c = result;
    }
    return result;
    }
    
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends