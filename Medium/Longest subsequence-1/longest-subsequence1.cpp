//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    void cntSub(int ind, vector<int> &a, int n, int temp,int &val)
    {
       if(ind == n)
       {
           val = max(val,temp);
           return;
       }
       
       for(int i = ind+1 ; i < n ; i++ )
       {
           if(ind == -1 )
           {
               cntSub(i,a,n,temp+1,val);
           }
           else
           {
               if(abs(a[i]-a[ind]) == 1)
               {
                   cntSub(i,a,n,temp+1,val);
               }
           }
       }
       val = max(val,temp);
       return;
    }
    
    int longestSubseq(int n, vector<int> &a) {
        int val = 0;
        cntSub(-1,a,n,0,val);
        return val;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends