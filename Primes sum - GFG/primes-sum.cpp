//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
 int prime1(int n)
    {
        if(n==1)   return 0;
         
        if(n==2)   return 1;
         
    for(int i=2;i*i<=n;i++) {
        if(n%i==0)    return 0;
    }
        return 1;
    }
    string isSumOfTwo(int N){
        for(int i=2;i<=(N/2);i++) {
            if(prime1(i)==1 && prime1(N-i)==1) {
                return "Yes";
            }
        }
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends