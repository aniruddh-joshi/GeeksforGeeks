//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int s,vector<bool> &vis,vector<int> adj[]) {
        vis[s] = true;
        for(int i=0;i<adj[s].size();i++) {
            if(vis[adj[s][i]] == false) {
                dfs(adj[s][i],vis,adj);
            }
        }
    }
    
	int findMotherVertex(int v, vector<int> adj[]) {
	    vector<bool> vis(v,false);
	    int tmp = 0;
	    for(int i=0;i<v;i++) {
	        if(vis[i] == false) {
	            dfs(i,vis,adj);
	            tmp = i;
	        }
	    }
	    fill(vis.begin(),vis.end(),false);
	    dfs(tmp,vis,adj);
	    for(int i=0;i<v;i++) {
	        if(vis[i] == false) {
	            return -1;
	        }
	    }
	    return tmp;
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
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends