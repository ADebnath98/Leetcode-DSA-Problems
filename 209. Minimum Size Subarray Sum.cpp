class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, mini = INT_MAX, left = 0, right = 0;
        for(int right=0; right<nums.size(); right++)
        {
            sum = sum + nums[right];
            while(sum >= target)
            {
                mini = min(mini,right-left+1);
                sum = sum - nums[left++];
            }
        }
        if(mini==INT_MAX)
        return 0;

        return mini;
    }
};