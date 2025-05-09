//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	vector<vector<int>> searchWord(vector<vector<char>> a, string s)
    {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> v;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                if (a[i][j] == s[0])
                {
                    int kl = 0;
                    for (int k = -1; k < 2; k++)
                    {                   //pair (k,l) check karega sabhi direction me eg (-1,0)== will check
                //in all upward direction like (i-1,j-0) ab to samajh gye honge 
                        for (int l = -1; l < 2; l++)
                        {
                            if (kl == 1)//mil gya 
                                break;
                            if (k == 0 && l == 0)
                            {
                                continue;//bcz ye to same cell hoga na (i-0,j-0)
                            }
                            else
                            {
                                int I = i, J = j, L;
                                for (L = 0; L < s.size(); L++)
                                {
                                    if (I >= 0 && J >= 0 && I < a.size() && J < a[i].size() && a[I][J] == s[L])
                                    {
                                        I += k;
                                        J += l;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                }
                                if (L == s.size())
                                {
                                    kl = 1;
                                    v.push_back({i, j});
                                }
                            }
                        }
                    }
                }
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends