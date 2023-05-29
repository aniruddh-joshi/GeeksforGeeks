//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>key(V,INT_MAX);
        vector<bool>visited(V,false);
        vector<int>parent(V,-1);
        
        int src=0;
        pq.push({0,src});
        key[src]=0;
        
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            visited[u]=true;
            
            for(auto v:adj[u]){
                int node=v[0];
                int weight=v[1];
                
                if(!visited[node] && key[node] > weight){
                    key[node] = weight;
                    parent[node] =u;
                    pq.push({key[node],node});
                }
            }
        }
        int sum=0;
        for(int i=1;i<V;i++){
            sum+=key[i];
        }
        return sum;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends