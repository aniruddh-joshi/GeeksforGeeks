//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       if(n==0){
           return 0;
       }
       vector<int>ans;
       ans.push_back(a[0]);
       
       for(int i=1;i<n;i++){
           if(a[i] > ans.back())
            ans.push_back(a[i]);
            else{
            //find index of just bda element
            int index= lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
            ans[index]=a[i];
        }
       }
       return ans.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends