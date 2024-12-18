//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < arr[mid + 1]) // current mid is in increasing part
            low = mid + 1;
        else // current mid is in decreasing part or is the maximum element
            high = mid;
    }
    return arr[low]; // maximum element
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends