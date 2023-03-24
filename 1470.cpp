class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        n=nums.size()/2;
        vector<int>ans(nums.size());
        int j=0;
        for(int i=0;i<n;i++){
            ans[j++]=nums[i];
            ans[j++]=nums[i+n];
        }
    return ans;
    }
};
