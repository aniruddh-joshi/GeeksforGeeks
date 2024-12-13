//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        int i=0;
        int n=arr.size();
        while(arr[i]<arr[i+1] && i<n-1)
        {
            i++;
        }
        int s=(i+1)%n;
        int e=(i+n);
        int maxi=arr[e%n];
        while(s<e)
        {
            int mid=s+(e-s)/2;
            if(arr[mid%n]<=arr[e%n])
            {
                e=mid;
            }
            else
            {
                s=mid+1;
            }
        }
        return arr[s];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends