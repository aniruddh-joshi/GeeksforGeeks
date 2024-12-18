//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int>pos, neg;
        for(int &it:arr){
            if(it<0) neg.push_back(it);
            else pos.push_back(it);
        }
        
        int i=0, j=0, ind=0;
        
        while(i<pos.size() && j<neg.size()){
            arr[ind++]=pos[i++];
            arr[ind++]=neg[j++];
        }
        
        while(i<pos.size()){
            arr[ind++]=pos[i++];
        }
        
        while(j<neg.size()){
            arr[ind++]=neg[j++];
        }
        return;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends