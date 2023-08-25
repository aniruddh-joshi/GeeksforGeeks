//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    void genNum(long long num, long long N, vector<long long>& result) {
        if (num>N) {
            return;
        }
        if (num>9) {
            result.push_back(num);
        }
        int lastDigit=num%10;
        if (lastDigit==0) {
            genNum(num*10+1,N,result);
        } else if (lastDigit==9) {
            genNum(num*10+8,N,result);
        } else {
            genNum(num*10+lastDigit-1,N,result);
            genNum(num*10+lastDigit+1,N,result);
        }
    }
    vector<long long>absDifOne(long long N) {
        vector<long long> result;
        for (int i=1;i<=9;i++) {
            genNum(i,N,result);
        }
        sort(result.begin(),result.end()); 
        return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
        {
            long long n;
            cin>>n;
            Solution ob;
            vector<long long> res = ob.absDifOne(n);
            for(int i = 0;i<res.size();i++)
                cout<<res[i]<<" ";
            if(res.size()==0)
                cout<<-1;
            cout<<endl;    
        }
}

// } Driver Code Ends