//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    void rearrange(long long *arr, int n) { 
    	if(n==1)    return;
    	int i=0;
    	int j=n-1;
    	vector<long long>ans;
    	while(i<=j){
    	    ans.push_back(arr[j]);
    	    ans.push_back(arr[i]);
    	    i++;
    	    j--;
    	}
    	for(int i=0;i<ans.size();i++){
    	    arr[i] = ans[i];
    	}
    }
};


//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends