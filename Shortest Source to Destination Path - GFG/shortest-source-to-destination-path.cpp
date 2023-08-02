//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
       queue<pair<int,int>>q;
       q.push({0,0});
       int dx[]={0,-1,0,1};
       int dy[]={-1,0,1,0};
       int steps=0;
       while(!q.empty())
       {
           int sz=q.size();
           for(int i=0;i<sz;i++)
           {
                   auto node=q.front();q.pop();
               int row=node.first;
               int col=node.second;
               
               if(row==X and col==Y)
               {
                   return steps;break;
               }
               for(int i=0;i<4;i++)
               {
                   int nrow=row+dx[i];
                   int ncol=col+dy[i];;
                   if(nrow>=0 and ncol>=0 and nrow<N and ncol<M and A[nrow][ncol]==1)
                   {
                       q.push({nrow,ncol});
                       A[nrow][ncol]=0;
                   }
               }
           }
           steps++;
       }
       return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends