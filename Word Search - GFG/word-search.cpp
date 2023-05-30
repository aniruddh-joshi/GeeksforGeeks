//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:


    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int j, int k) {
    if (k == word.size()) {
        return true;
    }
    
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[k]) {
        return false;
    }
    
    visited[i][j] = true;
    bool result = dfs(board, word, visited, i+1, j, k+1) ||
                  dfs(board, word, visited, i-1, j, k+1) ||
                  dfs(board, word, visited, i, j+1, k+1) ||
                  dfs(board, word, visited, i, j-1, k+1);
    visited[i][j] = false;
    
    return result;
}


    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0]) {
                if (dfs(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }
    }
    
    return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends