//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution
{
	public:
    int timer=1,ans=0;
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> disc(V,0),low(V,0),visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i])
                dfs(i,-1,adj,c,d,visited,disc,low);
        }
        return ans;
    }
    
    void dfs(int index,int parent,vector<int> adj[],int c,int d,vector<int> &visited,vector<int> &disc,vector<int> &low){
        visited[index]=1;
        low[index]=disc[index]=timer++;
        
        for(auto nbr:adj[index]){
            if(nbr==parent) continue;
            if(!visited[nbr]){
                
                dfs(nbr,index,adj,c,d,visited,disc,low);
                low[index] = min(low[index],low[nbr]);
                
                if(low[nbr]>disc[index]){ 
                    if(index==c and nbr==d)
                        ans=1;
                    else if(index==d and nbr==c)
                        ans=1;
                }
            }
            else
                low[index] = min(low[index],low[nbr]);
        }
        return;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends