//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if (str1.length() != str2.length()) {
            return false;
        }
        
        unordered_map<char, char> mapping;
        unordered_set<char> mappedChars;
        
        for (int i = 0; i < str1.length(); i++) {
            char c1 = str1[i];
            char c2 = str2[i];
            
            if (mapping.find(c1) != mapping.end()) {
                if (mapping[c1] != c2) {
                    return false;
                }
            } else {
                if (mappedChars.find(c2) != mappedChars.end()) {
                    return false;
                }
                mapping[c1] = c2;
                mappedChars.insert(c2);
            }
        }
        
        return true;
    }
};


//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends