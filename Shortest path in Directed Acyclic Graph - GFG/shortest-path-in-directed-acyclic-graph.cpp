//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<pair<int, int>>adj[n];  // {vertex, weight}
        for ( vector<int> &i : edges ) {
            adj[i[0]].push_back({ i[1], i[2] });
        } 
        vector<int> dis(n, 1e6);
        vector<int> vis(n);
        priority_queue<pair<int, int>> q;  // {weight, vertex}
        q.push({0, 0});
        dis[0] = 0;
        while ( !q.empty() ) {
            pair<int, int> t = q.top();
            q.pop();
            int u = t.second;
            if ( vis[u] == 1 ) {
                continue;
            }
            vis[u] = 1;
            for ( pair<int, int> &i : adj[u] ) {
                int v = i.first, w = i.second;
                if ( dis[v] > dis[u] + w ) {
                    dis[v] = dis[u] + w;
                    q.push({-dis[v], v});
                }
            } 
        }
        for ( int i = 0; i < n; ++i ) {
            if ( dis[i] == 1e6 ) dis[i] = -1;
        } 
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends