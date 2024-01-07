//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        int low=*std:: max_element(arr,arr+N);
        int high=std:: accumulate(arr,arr+N,0);
        int ans=low;
        while(low<=high){
            int mid= low+(high-low)/2;
            int count=1;
            int sum=arr[0];
            
            for(int i=1;i<N;i++){
            if((sum+arr[i])>mid){
                count++;
                sum=arr[i];
            }
            else{
                sum+=arr[i];
            }
        }
            if(count>K){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends