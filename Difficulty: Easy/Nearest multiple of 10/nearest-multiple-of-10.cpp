//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        int n = str.size();
        if (str.back() <= '5') {
            str.back() = '0';
        } else {
            int carry = 10 - (str.back() - '0');
            for (int i = n - 1; carry and i >= 0; i--) {
                carry += str[i] - '0';
                str[i] = '0' + (carry % 10);
                carry /= 10;
            }
            if (carry) str.insert(str.begin(), carry + '0');
        }
        return str;

    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends