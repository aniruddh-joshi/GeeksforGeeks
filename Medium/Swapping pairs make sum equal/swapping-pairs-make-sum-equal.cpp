//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        unordered_set<int> st;
        int s1 = 0, s2 = 0;
        for(int i = 0; i<n; i++){
            s1 += a[i];
        }
        for(int i = 0; i<m; i++){
            s2 += b[i];
            st.insert(b[i]);
        }
        int s = s1 + s2;
        if(s%2 == 1)    return -1;
        int temp = s/2;
        for(int i = 0; i<n; i++){
            int rem = s1 - a[i];
            if(rem >= temp) continue;
            int tofind = temp - rem;
            if(st.find(tofind) != st.end()){
                return 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends