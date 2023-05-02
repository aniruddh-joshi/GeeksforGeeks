//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int>heights(m,0);
        int max_area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j]==0){
                    heights[j]=0;
                }
                else{
                    heights[j]++;
                }
            }
            stack<int>s;
            for(int j=0;j<=m;j++){
                while(!s.empty() && (j==m||heights[s.top()]>=heights[j])){
                    int h=heights[s.top()];
                    s.pop();
                    int w=s.empty()?j:j-s.top()-1;
                    max_area=max(max_area,h*w);
                }
                s.push(j);
            }
        }
        return max_area;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends