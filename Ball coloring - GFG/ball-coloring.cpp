//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    unsigned long long int noOfWays(unsigned long long int n){
         return (unsigned long long int)2 + n*(n - 1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long int n;
        cin >> n;
        Solution ob;
        cout<<ob.noOfWays(n)<<endl;
    }
    return 0;
}

// } Driver Code Ends