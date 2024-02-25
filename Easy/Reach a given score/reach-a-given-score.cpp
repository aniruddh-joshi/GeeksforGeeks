//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends
class Solution {
    public:
    long long int count(long long int n) {
    	long long int remaining = 0, count = 0;
        for(int i=0;i<=(n/3);i++) {
            remaining = n - i*3;
            if(remaining % 5 != 0) continue;
            count += (remaining/10) + 1;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends