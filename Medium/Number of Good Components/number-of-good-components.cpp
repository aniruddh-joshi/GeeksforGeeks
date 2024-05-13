//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
    int find(vector<int> &repr, int u) {
        if(repr[u] == u)
            return u;
        return repr[u] = find(repr, repr[u]);
    }
  public:
    int findNumberOfGoodComponent(const int &e, const int &v, const vector<vector<int>> &edges) {
        // code here
        int res = 0;
        vector<int> repr(v + 1, 0), vc(v + 1, 1), ec(v + 1, 0);
        for(int i = 1; i <= v; i++)
            repr[i] = i;
        for(auto &E: edges) {
            int r1 = find(repr, E[0]), r2 = find(repr, E[1]);
            if(r1 == r2) {
                ec[r1]++;
                continue;
            }
            if(r1 > r2)
                swap(r1, r2);
            repr[r2] = r1;
            vc[r1] += vc[r2];
            ec[r1] += ec[r2] + 1;
            vc[r2] = ec[r2] = 0;
        }
        for(int i = 1; i <= v; i++)
            if(vc[i] && ec[i] == (vc[i] * (vc[i] - 1))/2)
                res++;
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends