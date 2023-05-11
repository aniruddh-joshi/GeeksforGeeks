//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void solve(string S,vector<string>&ans,int index){
	        //base call
	        if(index==S.length()){
	            ans.push_back(S);
	            return;
	        }
	        for(int i=index;i<S.length();i++){
	            if(i>index && S[i]==S[i-1]){
	                continue;       //skip duplicate 
	            }
	            swap(S[index],S[i]);
	            solve(S,ans,index+1);
	            
	            //backtracking
	            swap(S[i],S[index]);
	        }
	    }
	    
	    
		vector<string>find_permutation(string S)
		{
		    vector<string>ans;
		    int index=0;
		    
		    solve(S,ans,index);
		   //lexicographically sorted order
		    sort(ans.begin(),ans.end());
		    
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends