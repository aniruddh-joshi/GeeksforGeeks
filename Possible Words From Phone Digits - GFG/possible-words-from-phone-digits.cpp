//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    private:
    //Function to find list of all words possible by pressing given numbers.
    
    void solve(vector<int>& a,string output,int index,vector<string>&ans,string mapping[]){
        //base case
        if(index>=a.size()){
            ans.push_back(output);
            return;
        }
        int number=a[index];
        string value=mapping[number];
        
        for(int i=0;i<value.size();i++){
            output.push_back(value[i]);
            solve(a,output,index+1,ans,mapping);
            output.pop_back();
        }
    }
    
    public:
    vector<string> possibleWords(int a[], int N)
    {
        vector<string>ans;
        if(N==0){
            return ans;
        }
        vector<int>digits(a,a+N);
        string output;
        int index=0;
        string mapping[10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,mapping);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends