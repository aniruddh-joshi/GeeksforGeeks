//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    vector<string> ans;
    void solve(int ind, string S, string& temp){
        if(ind == S.size()) {
            ans.push_back(S);
            return;
        }
        for(int j=ind ; j<S.size() ; j++){
            swap(S[ind],S[j]);
            solve(ind+1, S, temp);
            swap(S[j],S[ind]);
        }
    }
    
    vector<string> permutation(string S)
    {
        string temp;
        solve(0,S,temp);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends