//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
       
    long long res = arr[0]; 
    long long curr = arr[0]; 
    
    for (int i = 1; i < arr.size(); ++i) { 
        curr = max(curr + arr[i], (long long)arr[i]); 
        res = max(res, curr); 
    }
    
    return res;
    }


};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends