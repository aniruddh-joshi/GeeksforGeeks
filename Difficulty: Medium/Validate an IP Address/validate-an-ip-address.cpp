//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        string cur="";
        int count=0;
        for (int i=0;i<str.size();i++)
        {
            if (str[i]=='.')
            {
                if (cur.size()==0) return false;
                if (cur[0]=='0' && cur.size()!=1) return false;
                if (cur.size()>=3 && cur>"255") return false;
                count++;
               
                cur="";
            }
            else cur+=str[i];
        }
        if (cur.size()==0) return false;
        if (cur[0]=='0' && cur.size()>1) return false;
        if (cur.size()>=3 && cur>"255") return false;
        count++;
       
        if (count!=4) return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends