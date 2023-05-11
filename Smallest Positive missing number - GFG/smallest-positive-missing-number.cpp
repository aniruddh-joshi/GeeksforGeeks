//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        //Step 1: Remove negative and zero with (n+1)
        for(int i=0;i<n;i++){
            if(arr[i]<=0){
                arr[i]=n+1;
            }
        }
        
        //Step 2: Mark all +ve number
        for(int i=0;i<n;i++){
            int num=abs(arr[i]);
            if(num<=n){
                arr[num-1]=-abs(arr[num-1]);
            }
        }
        
        //Step 3: Return the index of 1st unmarked 
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                return i+1;
            }
        }
        
        //Step 4: if all element are marked then smallest elemen is n+1
        return n+1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends