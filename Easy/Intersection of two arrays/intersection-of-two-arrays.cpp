//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function template for C++

class Solution {
  public:
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        sort(a,a+n);
        sort(b,b+m);
        int count = 0;
        int i=0;
        int j=0;
        
        while(i<n && j<m) {
            if(a[i] == b[j]) {
                count++;
                i++;
                j++;
                while(i<n && a[i-1] == a[i]) i++;
                while(j<m && b[j-1] == b[j]) j++;
            }
            else if(a[i] > b[j]) {
                j++;
            }
            else {
                i++;
            }
        }
        return count;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends