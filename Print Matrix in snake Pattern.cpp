

class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        int n = matrix.size();
        vector<int> result;
        bool flag = true;
        
        for(int i=0;i<n;i++){
            if(flag){
                for(int j=0;j<n;j++){
                    result.push_back(matrix[i][j]);
                }
            }
            else{
                for(int j=n-1;j>=0;j--){
                    result.push_back(matrix[i][j]);
                }
            }
            flag = !flag;
        }
        
        return result;
    }
};
