//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << convertFive(n) << endl;
    }
}
// } Driver Code Ends


/*you are required to complete this method*/
int convertFive(int n) {
    // Your code here
    int num = 0, power = 1;
    while (n > 0) {
        int digit = n % 10;
        if (digit == 0) {
            digit = 5;
        }
        num += digit * power;
        power *= 10;
        n /= 10;
    }
    return num;
}