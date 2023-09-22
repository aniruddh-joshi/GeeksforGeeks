//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> find(int arr[], int n , int x )
    {
        vector<int> res(2, -1); // initialize result to {-1, -1}
        
        // find first occurrence of x
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (l < n && arr[l] == x) {
            res[0] = l;
        } else {
            return res; // x not found
        }
        
        // find last occurrence of x
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] <= x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        res[1] = r;
        
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends