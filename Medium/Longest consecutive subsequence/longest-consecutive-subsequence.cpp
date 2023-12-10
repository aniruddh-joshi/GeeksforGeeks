//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      int maxi=0;
      unordered_map<int,bool>mp;
      for(int i=0;i<N;i++){
          mp[arr[i]]=true;
      }
      for(int i=0;i<N;i++){
          int c=1;
          if(mp[arr[i]-1]==false){
              int y=arr[i]+1;
              while(mp[y++]==true){
                  c++;
              }
              maxi=max(c,maxi);
          }
      }
      return maxi;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends