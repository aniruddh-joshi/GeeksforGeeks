//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int value(char c){
            if(c=='I'){
                return 1;
            }
            else if(c=='V'){
                return 5;
            }
            else if(c=='X'){
                return 10;
            }
            else if(c=='L'){
                return 50;
            }
            else if(c=='C'){
                return 100;
            }
            else if(c=='D'){
                return 500;
            }
            return 1000;
        }
    int romanToDecimal(string &str) {
        int ans=value(str.back());
        for(int i=str.length()-2;i>=0;i--){
            if(value(str[i])<value(str[i+1])){
                ans=ans-value(str[i]);
            }
            else{
                ans=ans+value(str[i]);
            }
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
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends