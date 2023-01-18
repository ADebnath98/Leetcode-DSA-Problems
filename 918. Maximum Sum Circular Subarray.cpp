class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int min_sum = nums[0], max_sum = nums[0];
        int currMin = 0, currMax = 0;
        int sum = 0;
        for(int num : nums)
        {
            currMax = max(currMax, 0) + num;
            max_sum = max(max_sum, currMax);
            currMin = min(currMin, 0) + num;
            min_sum = min(min_sum, currMin);
            sum += num;
        }
        if(sum == min_sum)
        {
            return max_sum;
        }
        return max(max_sum, sum - min_sum);
    }
};