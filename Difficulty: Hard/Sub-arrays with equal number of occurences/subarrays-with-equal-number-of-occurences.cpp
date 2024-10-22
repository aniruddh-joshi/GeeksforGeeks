//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == x) {
                arr[i] = -1;  // Replace x with -1
            }
            else if (arr[i] == y) {
                arr[i] = 1;   // Replace y with 1
            }
            else {
                arr[i] = 0;   // Replace all other elements with 0
            }
        }
        
        // Step 2: Use a running sum to find subarrays whose sum is zero
        unordered_map<int, int> ma;  // Map to store frequency of prefix sums
        int sum = 0;  // Running sum of the array
        int count = 0;  // Count of subarrays with sum zero

        // Traverse the modified array to find subarrays with sum 0
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];  // Update the running sum

            // If the running sum is zero, it means the subarray from index 0 to i has sum 0
            if (sum == 0) {
                count++;
            }

            // If the current sum has been seen before, it means there exist subarrays
            // between previous occurrences and the current index that sum to zero
            if (ma.find(sum) != ma.end()) {
                count += ma[sum];  // Add the frequency of the previous sum to the count
            }

            // Increment the frequency of the current running sum in the map
            ma[sum]++;
        }

        // Return the total count of subarrays with sum zero
        return count;

    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends