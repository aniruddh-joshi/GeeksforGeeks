//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        int i=0,j=0,n=a.size(),m=b.size();
        vector<int>res;
        while(i<n && j<m){
            if(a[i]==b[j]){
                res.push_back(a[i]);
                i++;
                j++;
                while(a[i]==res.back()) i++;
                while(b[j]==res.back())  j++;
            }else if(a[i]<b[j]){
                res.push_back(a[i]);
                i++;
            }else{
                res.push_back(b[j]);
                j++;
            }
        }
        
        while(i<n){
            while(i<n && a[i]==res.back())  i++;
            if(i==n)break;
            res.push_back(a[i]);
        }
  
        while(j<m){
            while(j<m && b[j]==res.back()) j++;
            if(j==m)break;
            res.push_back(b[j]);
        }
        
        return res;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends