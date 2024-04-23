//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        int t1=1;
        int t2=1;
        if(n==1 || n==2)
            return 1;
        for(int i=3;i<=n;i++)
        {
            int t3=(t1+t2)%1000000007;
            t1=t2;
            t2=t3;
        }
        return t2%1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends