class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n) {
        vector<int>ans(2,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<=j)    ans[0]+=matrix[i][j];
                if(i>=j)    ans[1]+=matrix[i][j];
            }
        }
        return ans;
    }
};
