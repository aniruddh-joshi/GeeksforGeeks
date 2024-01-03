//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int smallestSubstring(string s) {
    vector<int> A(3, 0);
        int high=0, low=0, n=s.size(), ans=1e9;
        while(high<n) {
            A[s[high]-'0']++;
            while(A[0]&&A[1]&&A[2]) {
                ans=min(ans, high-low+1);
                A[s[low++]-'0']--;
            }
            high++;
        }
        return ans==1e9?-1:ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends