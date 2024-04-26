//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        int i=0,j=0,k=0;
        while(true) {
            if(matrix[i][j]==1) {
                matrix[i][j]=0;
                k=(k+1)%4;
            }
            i+=dir[k][0];
            j+=dir[k][1];
            if(i<0 || j<0 || i>=n || j>=m) {
                return {i-dir[k][0],j-dir[k][1]};
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends