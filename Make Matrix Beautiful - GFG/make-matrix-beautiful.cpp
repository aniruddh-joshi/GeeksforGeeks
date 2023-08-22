//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int maxelement(vector<int> sumrows, int n){
        int ans = sumrows[0]; 
        for(int i=0; i<n; i++){
            ans = max(ans,sumrows[i]); 
        }
        return ans; 
    }
    public:
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        vector<int> sumrows(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sumrows[i]+=matrix[i][j]; 
            }
        }
        vector<int> sumcols(n); 
        for(int j=0; j<n; j++){
            for(int i=0; i<n; i++){
                sumcols[j]+=matrix[i][j]; 
            }
        }
        
        int maxsumrow = maxelement(sumrows,n);
         
        int maxsumcol = maxelement(sumcols,n);
        
        int target= max(maxsumrow, maxsumcol);
        
        int count=0; 
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
               
                int temp = min(target - sumrows[i], target-sumcols[j]);
                matrix[i][j]+= temp; 
                sumrows[i] = sumrows[i] + temp; 
                sumcols[j] = sumcols[j] + temp;
                count+=temp;
            }
        }
        return count; 
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends