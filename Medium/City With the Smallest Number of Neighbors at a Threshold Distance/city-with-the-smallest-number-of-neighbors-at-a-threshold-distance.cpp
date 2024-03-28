//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        
        //adjacency matrix
        vector<vector<int>> floyd(n,vector<int>(n,1e9));
        for(auto it:edges)
        {
            floyd[it[0]][it[1]]=it[2];
            floyd[it[1]][it[0]]=it[2];
        }
        
        //floyd warshall
        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                floyd[i][j]=min(floyd[i][j],floyd[i][via]+floyd[via][j]);
            }
        }
        
        //City With the Smallest Number of Neighbors at a Threshold Distance
        int node=-1;
        int mini=1e9;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;
                
                if(floyd[i][j]<=distanceThreshold)
                cnt++;
            }
            
            if(cnt<mini)
            {
                mini=cnt;
                node=i;
            }
            else if(cnt==mini)
            node=max(node,i);
        }
        return node;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends