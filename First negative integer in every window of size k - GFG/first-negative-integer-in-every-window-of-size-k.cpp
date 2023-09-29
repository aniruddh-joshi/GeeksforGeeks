//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                           long long int N, long long int K) {
    vector<long long> result;
    deque<long long> negIndices;

    // Traverse the array with a sliding window
    for (long long i = 0; i < N; i++) {
        // If the element at the current index is negative, add its index to the queue
        if (A[i] < 0) {
            negIndices.push_back(i);
        }

        // If the leftmost element in the window is out of the window, remove it from the queue
        if (!negIndices.empty() && negIndices.front() <= i - K) {
            negIndices.pop_front();
        }

        // If the current window size is equal to K, add the first negative integer to the result
        if (i >= K - 1) {
            if (negIndices.empty()) {
                // No negative integer in the current window
                result.push_back(0);
            } else {
                result.push_back(A[negIndices.front()]);
            }
        }
    }

    return result;
}
