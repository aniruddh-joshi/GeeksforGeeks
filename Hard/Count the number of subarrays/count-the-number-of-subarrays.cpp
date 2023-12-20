//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long subarray(int n, vector<int> nums, long long limit) {
        int left = 0;
        int right = 0;
        long long ans = 0;
        long long currSum = 0;
    
        while (right < n) {
            currSum += nums[right];
            while (currSum > limit) {
                currSum -= nums[left];
                left ++;
            }
            ans += (right-left+1);
            right ++;
        }
        return ans;
    }
    
    long long countSubarray(int n, vector<int> nums, long long L, long long R) {
        return subarray(n, nums, R) - subarray(n, nums, L-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends