//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool dfs(int src,unordered_map<int,bool>&visited,vector<int> adj[]){
      
        unordered_map<int,int>parent;
        
        parent[src]=-1;
        visited[src]=1;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            for(auto neighbour : adj[front]){
                if(visited[neighbour]==true && neighbour != parent[front]){
                    return true;
                }
                else if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour]=1;
                    parent[neighbour]=front;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool>visited;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans= dfs(i,visited,adj);
                
                if(ans==1){
                    return true;
                }
            }
        }
            return false;
        }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends