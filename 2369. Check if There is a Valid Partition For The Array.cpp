class Solution {
public:

    bool solve(vector<int>& nums, int i, vector<int>& dp){
        bool res = false;
        if(i >= nums.size())    return true;
        if(dp[i] != -1) return dp[i];
        // rule-1
        if(i+1 < nums.size() && nums[i] == nums[i+1])
            res |= solve(nums, i+2, dp);
        // rule-2
        if(i+2 < nums.size() && nums[i] == nums[i+1] && nums[i+1] == nums[i+2])
            res |= solve(nums, i+3, dp);
        // rule-3
        if(i+2 < nums.size() && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1)
            res |= solve(nums, i+3, dp);
    
        return dp[i] = res;
    }

    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(nums, 0, dp);
    }
};