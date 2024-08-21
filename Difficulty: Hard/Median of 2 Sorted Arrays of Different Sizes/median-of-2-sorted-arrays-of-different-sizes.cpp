//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    double MedianOfArrays(std::vector<int>& array1, std::vector<int>& array2) {
        // Ensure array1 is the smaller array
        if (array1.size() > array2.size()) {
            return MedianOfArrays(array2, array1);
        }

        int m = array1.size();
        int n = array2.size();
        int low = 0, high = m;

        while (low <= high) {
            int partition1 = (low + high) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;

            int maxLeft1 = (partition1 == 0) ? INT_MIN : array1[partition1 - 1];
            int minRight1 = (partition1 == m) ? INT_MAX : array1[partition1];

            int maxLeft2 = (partition2 == 0) ? INT_MIN : array2[partition2 - 1];
            int minRight2 = (partition2 == n) ? INT_MAX : array2[partition2];

            // Check if we have found the correct partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 0) {
                    return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
                } else {
                    return std::max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                high = partition1 - 1;
            } else {
                low = partition1 + 1;
            }
        }

    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends