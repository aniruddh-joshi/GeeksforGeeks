class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int start=0,end=0;
        int currSum=0;
        int window=INT_MAX;

        for(end=0;end<n;end++){
            currSum+=nums[end];
            while(currSum >= target){
                if(currSum >= target){
                    window=min(window, end-start+1);
                    currSum-=nums[start++];
                }
            }
        }
        if(window==INT_MAX)     return 0;
        else    return window;
    }
};
