//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string removeKdigits(string s, int k) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            while(st.size() > 0 && k > 0 && st.top() > s[i]){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k--){
            st.pop();
        }
        if(st.size() == 0)return "0";
        string tmp = "";
        
        while(st.size() > 0){
            tmp.push_back(st.top());
            st.pop();
        }
        reverse(tmp.begin(),tmp.end());
        int i = 0;
        while(tmp[i]=='0'){
            i++;
        }
        if(i==tmp.size())return "0";
        
        return tmp.substr(i);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends