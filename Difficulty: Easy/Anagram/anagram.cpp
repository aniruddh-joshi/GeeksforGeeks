//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;

        vector<int> v1(26, 0), v2(26, 0);
        for (char& e : s1) v1[e - 'a']++;  
        for (char& e : s2) v2[e - 'a']++;  
        
        return (v1 == v2);  
    }

};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends