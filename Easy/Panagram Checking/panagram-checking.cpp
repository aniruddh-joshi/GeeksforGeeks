//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution {
  public:
    bool checkPangram (string s) {
    transform(s.begin(),s.end() , s.begin() , ::tolower);
        unordered_map<char,int> freq;
        for(char &ch:s){
            if(isalpha(ch)){
                freq[ch]++;
            }
        }
        return freq.size()==26?1:0;
    }
};


//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends