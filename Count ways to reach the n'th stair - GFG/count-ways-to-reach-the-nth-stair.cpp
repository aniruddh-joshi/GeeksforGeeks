//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int solve(int n){
    
        int prev1=1;
        int prev2=1;
        
        //Step3:
        for(int i=2;i<=n;i++){
            int curr=(prev1+prev2) % 1000000007;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        return solve(n);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends