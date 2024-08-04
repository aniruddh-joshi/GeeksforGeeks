//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        auto lambda=[](pair<int,int>& p1,pair<int,int>& p2)
        {
            return p1.second<p2.second;
        };
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++)
        {
            vec[i]=make_pair(start[i],end[i]);
        }
        sort(vec.begin(),vec.end(),lambda);
        int count=0;
        int prevEnd=-1;
        for(int i=0;i<n;i++)
        {
            if(vec[i].first>prevEnd)
            {
                count++;
                prevEnd=vec[i].second;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends