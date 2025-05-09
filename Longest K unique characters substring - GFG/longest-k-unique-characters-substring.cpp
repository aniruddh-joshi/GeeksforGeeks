//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
  public:
    int longestKSubstr(string s, int k) {
      map<char,int>mp;
        int cnt = 0;
        int start=0, end = 0;
        int ans = -1;
        while(end < s.size()){
            mp[s[end]]++;
            // distinct count check after add
            if(mp[s[end]] == 1){
                cnt++;
            }
            while(cnt > k){
                mp[s[start]]--;
               // distinct count count after remove
                if(mp[s[start]]==0){
                    cnt--;
                }
                start++;
            }
            if(cnt == k){
                ans = max(ans, end-start+1);
            }
            end++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends