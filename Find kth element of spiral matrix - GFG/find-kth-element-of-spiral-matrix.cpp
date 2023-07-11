//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int ru=0;      //row up
 		int rd=n-1;     //row down
 		int cl=0;       //column left
 		int cr=m-1;     //column right
 		
 		vector<int> res;
 		while(cl<=cr && ru<=rd){
 		    for(int i=cl;i<=cr;i++){
 		        res.push_back(a[ru][i]);
 		    }
 		    ru++;
 		    for(int i=ru;i<=rd;i++){
 		        res.push_back(a[i][cr]);
 		    }
 		    cr--;
 		    for(int i=cr;i>=cl;i--){
 		        res.push_back(a[rd][i]);
 		    }
 		    rd--;
 		    for(int i=rd;i>=ru;i--){
 		        res.push_back(a[i][cl]);
 		    }
 		    cl++;
 		}
 		return res[k-1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends