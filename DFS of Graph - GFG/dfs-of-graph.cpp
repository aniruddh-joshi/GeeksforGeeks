//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
  void dfs(vector<int>adj[],unordered_map<int,bool>&visited,vector<int>&ans,int node){
      //ans store
      ans.push_back(node);
      //marks vvisited
      visited[node]=true;
      
      //har connected call ke liye recurssive call
      for(auto i: adj[node]){
          if(!visited[i]){
              dfs(adj,visited,ans,i);
          }
      }
  }
  
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        unordered_map<int,bool>visited;
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(adj,visited,ans,i);
            }
        }
        return ans;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends