//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    public:
    //Function to insert heap.
     priority_queue<int> maxHeap;//left
    priority_queue<int,vector<int>,greater<int>> minHeap;//right
    void insertHeap(int &x)
    {
        maxHeap.push(x);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(minHeap.size()>maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxHeap.size()==minHeap.size()){
            return (double)((maxHeap.top() + minHeap.top())/2);
        }
        return (double)maxHeap.top();
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends