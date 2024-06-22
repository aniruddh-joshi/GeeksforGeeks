//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        long long maxNumber = -1;
        long long currentNumber = 0;
        bool inNumber = false;

        for (char c : sentence) {
            if (isdigit(c)) {
                currentNumber = currentNumber * 10 + (c - '0');
                inNumber = true;
            } else {
                if (inNumber && to_string(currentNumber).find('9') == string::npos) {
                    if (currentNumber > maxNumber) {
                        maxNumber = currentNumber;
                    }
                }
                inNumber = false;
                currentNumber = 0;
            }
        }

        if (inNumber && to_string(currentNumber).find('9') == string::npos) {
            if (currentNumber > maxNumber) {
                maxNumber = currentNumber;
            }
        }

        return maxNumber;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends