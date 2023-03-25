class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool>result(n,false);
        int max_candies=*max_element(candies.begin(),candies.end());
        for(int i=0;i<n;i++){
            result[i]=(candies[i]+extraCandies >= max_candies);
        }
        return result;
    }
};
