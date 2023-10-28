//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int is_bleak(int n) {
	    // Code here.  
	   int i=max(0,n-31);
	   for(int j=i;j<=n;j++) {
	       int sb=__builtin_popcount(j)+j;
	       if(sb==n) return 0;
	   }
	   return 1;
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends