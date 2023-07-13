//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
#include<set>
class Solution
{
    public:
    bool isFrequencyUnique(int n, int arr[])
    {
        map<int,int>freqMap;
        
        for(int i=0;i<n;i++){
            freqMap[arr[i]]++;
        }
        
        set<int>uniqueFreq;
        
        for(const auto&pair : freqMap){
            uniqueFreq.insert(pair.second);
        }
        return (uniqueFreq.size()==freqMap.size());
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        bool ans=ob.isFrequencyUnique(n,arr);
        if(ans)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
}
// } Driver Code Ends