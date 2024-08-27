//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    void solve(vector<int>&arr, vector<int>&ans){
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                ans[i] = arr[i - 1];
            } else {
                int j = i - 1;
                while (j >= 0) {
                    if (ans[j] < arr[i]) {
                        ans[i] = ans[j];
                        break;
                    }
                    j--;
                }
            }
        }
    }
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> leftSmall(n, 0);
        vector<int> rightSmall(n, 0);

        solve(arr,leftSmall);
        reverse(arr.begin(),arr.end());
        solve(arr,rightSmall);
        reverse(rightSmall.begin(),rightSmall.end());
         

        int maxDiff = 0;
        for (int i = 0; i < n; ++i) {
            maxDiff = max(maxDiff, abs(leftSmall[i] - rightSmall[i]));
        }

        return maxDiff;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends