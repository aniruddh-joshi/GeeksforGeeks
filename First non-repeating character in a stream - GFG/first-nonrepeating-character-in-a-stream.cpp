//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char, int> freq;
            queue<char> q;
            string ans = "";
            for (char c : A) {
                freq[c]++;
                q.push(c);
            while (!q.empty() && freq[q.front()] > 1) {
                q.pop();
            }
            if (q.empty()) {
                ans += "#";
            }
            else {
                ans += q.front();
            }
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends