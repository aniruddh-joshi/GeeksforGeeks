// User function Template for C++

class Solution{
public:
   int calc(int i, int j,int n, int m, vector<vector<int>> &mat, int k){
          int sum=0;
          for(int l=i-k;l<=i+k;l++){if(j>=k and l>=0 and l<n)sum+=mat[l][j-k];}
          for(int l=i-k;l<=i+k;l++){if(j+k<m and l>=0 and l<n)sum+=mat[l][j+k];}
          for(int l=j-k+1;l<=j+k-1;l++){if(i>=k and l>=0 and l<m)sum+=mat[i-k][l];}
          for(int l=j-k+1;l<=j+k-1;l++){if(i+k<n and l>=0 and l<m)sum+=mat[i+k][l];}
        return sum;
   }
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> qr[])
    {
        vector<int>ans(q);
        for(int i=0;i<q;i++){
            ans[i]=calc(qr[i][1], qr[i][2],n, m, mat, qr[i][0]);
        }
        return ans;
    }
};
