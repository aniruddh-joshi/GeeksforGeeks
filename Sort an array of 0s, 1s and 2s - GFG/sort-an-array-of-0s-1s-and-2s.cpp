//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int i=0;
        int c1=0,c2=0,c3=0;
        for(int j=0;j<n;j++)
        {
            if(a[j]==0) c1++;
            if(a[j]==1) c2++;
            if(a[j]==2) c3++;
        }
        for(int j=0;j<c1;j++) a[i++]= 0;
        for(int j=0;j<c2;j++) a[i++]= 1;
        for(int j=0;j<c3;j++) a[i++]= 2;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends