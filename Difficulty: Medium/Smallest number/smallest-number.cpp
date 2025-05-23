//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        // Check if it's possible to create such a number
        if (s > 9 * d) return "-1";
        
        string result(d, '0');  // Initialize a string with 'd' zeroes
        s--; // Reserve 1 for the most significant digit
        
        // Fill the number from the least significant digit to the most
        for (int i = d - 1; i > 0; i--) {
            if (s > 9) {
                result[i] = '9';
                s -= 9;
            }
            else {
                result[i] = '0' + s;
                s = 0;
            }
        }
        result[0] = '1' + s; // Put the remaining sum in the most significant digit
        
        return result;
    }

};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends