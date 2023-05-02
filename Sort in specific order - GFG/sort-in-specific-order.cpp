//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    void sortIt(long long arr[], long long n)
    {
        vector<long long>even;
        vector<long long>odd;
        
        for(int i=0;i<n;i++){
            if(arr[i]%2==0){
                even.push_back(arr[i]);
            }
            else{
                odd.push_back(arr[i]);
            }
        }
        sort(odd.rbegin(),odd.rend());
        sort(even.begin(),even.end());
        
        int k=0;
        for(int i=0;i<odd.size();i++){
            arr[k++]=odd[i];
        }
        for(int i=0;i<even.size();i++){
            arr[k++]=even[i];
        }
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long arr[n];

        for (int i = 0; i < n; i++) 
            cin >> arr[i];
        
        Solution ob;
        ob.sortIt(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends