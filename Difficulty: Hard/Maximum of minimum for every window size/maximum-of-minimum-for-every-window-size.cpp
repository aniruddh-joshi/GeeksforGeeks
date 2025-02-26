//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
    int n=arr.size();
        vector<int>pse(n),nse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            
            nse[i]=st.empty()?n:st.top();
            st.push(i);
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<pse[i]<<" "<<nse[i]<<endl;
        // }
        
        vector<int>ans(n+1,0);
        for(int i=0;i<n;i++){
            int len=nse[i]-pse[i]-1;
            ans[len]=max(arr[i],ans[len]);
        }
        
        // ama amuk 0 ave che eg len=4,5,6
        // but ama je ans avse ae len=7 na barabar aj avse
        // cause 20 ans ava mate atmost len=3
        for(int i=n-1;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
        }
        
        return vector<int>(ans.begin()+1,ans.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends