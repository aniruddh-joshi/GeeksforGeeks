//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        //create adj list
        unordered_map<int,list<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //do bfs
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;
        
        queue<int>q;
        q.push(src);
        parent[src]=-1;
        visited[src]=true;
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            for(auto i: adj[front]){
                if(!visited[i]){
                    visited[i]=true;
                    parent[i]=front;
                    q.push(i);
                }
            }
        }
        //prepare shortest path
        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                ans[i] = 0;
                int currentNode = i;
                while (currentNode != src) {
                    currentNode = parent[currentNode];
                    ans[i]++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends