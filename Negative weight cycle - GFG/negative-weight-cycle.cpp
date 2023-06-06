//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	     vector<int> dis(n,1e8);
	    for(int j=0;j<n-1;j++)
	    {
	        for(int i=0;i<edges.size();i++)
	        {
	            if(dis[edges[i][0]]+ edges[i][2] < dis[edges[i][1]])
	                dis[edges[i][1]]= edges[i][2] +dis[edges[i][0]];
	            
	        }
	    }
	  
	        for(int i=0;i<edges.size();i++)
	        {
	            if(dis[edges[i][0]]+ edges[i][2] < dis[edges[i][1]])
	                return 1;
	            
	        }
	        return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends