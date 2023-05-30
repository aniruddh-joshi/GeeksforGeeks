//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    bool flag;
    void dfs(int src,int parent, vector<bool>&visited,vector<int>adj[])
    {
        if(visited[src]==false)
        {
            visited[src]=true;
            for(int i=0;i<adj[src].size();i++)
            {
                if(adj[src][i]!=parent)
                dfs(adj[src][i],src,visited,adj);
            }
            
        }
        else
        {
           flag= true ;
        }
    }
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    flag=false;
	    vector<bool>visited(V,false);
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        {
	            dfs(i,i,visited,adj);
	        }
	    }
	    
	    return flag;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends