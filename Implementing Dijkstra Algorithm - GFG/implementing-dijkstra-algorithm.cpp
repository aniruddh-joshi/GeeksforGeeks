//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //creation of ditance array with infinite value
        vector<int>dist(V);
        for(int i=0;i<V;i++)
            dist[i]=INT_MAX;
            
        //creation of set on basis(distace,node)
        set<pair<int,int>>st;
        //initialize distance and set with source
        dist[S]=0;
        st.insert(make_pair(0,S));
        
        while(!st.empty()){
            //fetch top record
            auto top=*(st.begin());
            int nodeDistance=top.first;
            int topNode=top.second;
            
            //remove top record now
            st.erase(st.begin());
            //traverse on neighbour
            for(auto neighbour: adj[topNode]){
                
                int neighbourNode= neighbour[0];
                int neighbourWeight= neighbour[1];
                if(nodeDistance + neighbourWeight < dist[neighbourNode]){
                    auto record=st.find(make_pair(dist[neighbourNode],neighbourNode));
                    
                //if record found, then erase it
                if(record !=st.end()){
                    st.erase(record);
                }
                
                //distance update
                dist[neighbourNode]= nodeDistance + neighbourWeight;
                
                //record push in set
                st.insert(make_pair(dist[neighbourNode],neighbourNode));
                }
            }
        }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends