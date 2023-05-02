//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
    // Write your code here
        int left=1,right=accumulate(sweetness.begin(),sweetness.end(),0);
        while(left<=right){
            int mid=left+(right - left)/2;
            int pieces = 0,curr_sweetness=0;
            for(int i=0;i<sweetness.size();i++){    //(int s: sweetness)
                int s=sweetness[i];
                curr_sweetness+=s;
                if(curr_sweetness>=mid){
                    pieces++;
                    curr_sweetness=0;
                }
            }
            if(pieces>=K+1){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return right;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends