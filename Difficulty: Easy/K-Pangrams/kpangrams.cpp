//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        vector<int> freq(26);
        for(const char & ch : str){
            if(ch <= 'z' && ch >='a')
                freq[ch-'a']++;
        }
        int extra=0,empty=0;
        for(size_t i=0; i<26; i++){
            if(freq[i] == 0){
                empty++;
            }else{
                extra += freq[i]-1;
            }
        }
        if(empty <= extra && empty <= k){
            return true;
        }
        return false;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends