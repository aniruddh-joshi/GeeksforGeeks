//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        set<int> temp ; 
        for (int i =0  ; i < n ; i++) {
            temp.insert(arr1[i]) ; 
        }
        for (int i =0  ; i < m ; i++) {
            temp.insert(arr2[i]) ; 
        }
        
        vector<int> ans ; 
        for(auto i : temp) {
            ans.push_back(i) ; 
        }
        
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends