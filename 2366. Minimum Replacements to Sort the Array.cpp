// Runtime: 46 ms, faster than 97.30% of C++ online submissions for Minimum Replacements to Sort the Array.
// Memory Usage: 53.95 MB, less than 100.00% of C++ online submissions for Minimum Replacements to Sort the Array

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {
        ios_base::sync_with_stdio(0);
        long long length = nums.size(), operations = 0, limit = nums[length - 1];
        for (int i = length - 2; i >= 0; i--)
        {
            if (nums[i] <= limit)
                limit = nums[i];
            else
            {
                long long partitions = nums[i] / limit + (nums[i] % limit != 0);
                limit = nums[i] / partitions;
                operations += partitions - 1;
            }
        }
        return operations;
    }
};