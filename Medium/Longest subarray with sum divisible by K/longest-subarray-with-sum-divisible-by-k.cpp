//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k) {
	    int maxlen=0,sum=0;
	    
	    unordered_map<int,int> remSum;
	    remSum[0]=-1;
	    
	    for(int i=0;i<n;i++){
	        sum=(sum+arr[i]);
	        int rem = sum%k;
	        if(rem<0) rem+=k;
	        if(remSum.find(rem)!=remSum.end()){
	            int len= i-remSum[rem];
	            maxlen=max(maxlen,len);
	        }
	        else{
	            remSum[rem]=i;
	        }
	    }
	    return maxlen;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends