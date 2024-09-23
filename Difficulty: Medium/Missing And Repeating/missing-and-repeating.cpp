//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        unordered_map<int,int>  mp ; 
        for(int i =0 ; i < n ; i ++) 
        {
            mp[arr[i]] ++ ; 
        }  
        int n2 = 0 ,  nm = 0 ;  
        for(int i = 1 ; i <=n ; i ++) 
        {
            if(mp[i] == 2)  
            n2 = i ; 
            if(mp[i] == 0) 
            nm = i ; 
        } 
        return {n2,nm} ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends