//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        int child1,child2;
        for(int i=0;i<n;i++){
            child1=2*i+1;
            child2=2*i+2;
            if(child1<n){
                if(arr[i]<arr[child1]) return 0;
            }
            if(child2<n){
                if(arr[i]<arr[child2]) return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends