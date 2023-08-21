//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>v;
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==1){
                    if(i>0 && matrix[i-1][j]==0) ans++;
                    if(j>0 && matrix[i][j-1]==0) ans++;
                    if(i<m-1 && matrix[i+1][j]==0) ans++;
                    if(j<n-1 && matrix[i][j+1]==0) ans++;
                    if(i>0 &&j>0 && matrix[i-1][j-1]==0)ans++;
                    if(i>0 && j<n-1 && matrix[i-1][j+1]==0) ans++;
                    if(i<m-1 && j>0 && matrix[i+1][j-1]==0) ans++;
                    if(i<m-1 && j<n-1 && matrix[i+1][j+1]==0) ans++;
                    
                    if(ans%2==0 && ans>0){
                        v.push_back(ans);
                    }
                    ans=0;
                }
            }
        }
        return v.size();
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends