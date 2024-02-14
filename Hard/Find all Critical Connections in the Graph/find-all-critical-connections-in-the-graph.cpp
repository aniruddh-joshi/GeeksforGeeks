//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<vector<int>> criticalConnections(int v, vector<int> adj[]) {
        // Code here
        vector<vector<int>> ans;
        vector<int> rank(v, -1), vis(v, 0);
        dfs(0, -1, rank, 0, adj, ans, vis);
        for (int i = 0; i < ans.size(); i++) {
            sort(ans[i].begin(), ans[i].end());
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    int dfs(int i, int p, vector<int>& rank, int k,
            vector<int> adj[], vector<vector<int>>& ans,
            vector<int>& vis) {
        rank[i] = k;
        vis[i] = 1;
        int minDepth = INT_MAX;

        for (auto ch : adj[i]) {
            if (ch != p) {
                if (vis[ch]) {
                    minDepth = min(minDepth, rank[ch]);
                }
                else {
                    int minRank = dfs(ch, i, rank, k + 1, adj,
                                      ans, vis);
                    if (rank[i] < minRank) {
                        ans.push_back({ i, ch });
                    }
                    minDepth = min(minRank, minDepth);
                }
            }
        }
        return minDepth;
    }
};


//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends