//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int Maximize(int a[],int n)
    {
        int mod = 1000000007;
        
        // Sort the array in descending order
        long long sum = 0;
        sort(a, a + n);
        
        
        
        // Calculate the sum of arr[i]*i for i = 0 to n-1
        for(int i = 0; i < n; i++){
            sum += (long long)a[i] * i;
            sum %= mod;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.Maximize(a,n)<<endl;
    }
}
// } Driver Code Ends