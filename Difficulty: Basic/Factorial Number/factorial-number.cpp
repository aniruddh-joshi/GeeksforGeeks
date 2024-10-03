//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isFactorial(int N) {
    int fact = 1;
    if (N == 1) return 1;

    for (int i = 1; fact <= N; i++) {
        if (fact == N) return 1;
        fact *= i;
    }
    
    return 0;
}

};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isFactorial(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends