//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        // Code here
        vector<pair<int,int>>v;
        for(int i=0;i<N;i++){
            v.push_back(make_pair(lines[i][0],1));
            v.push_back(make_pair(lines[i][1]+1,-1));
        }
        sort(v.begin(),v.end());
        int ans=0,s=0;
        for(int i=0;i<2*N;i++){
            s+=v[i].second;
            ans=max(ans,s);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends