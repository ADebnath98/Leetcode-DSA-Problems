class Solution {
public:
    void backtrack(vector<vector<int>>& res, vector<int> nums, vector<int>& temp, vector<int>& vis, int n)
    {
        if (temp.size() == n)
        {
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                temp.push_back(nums[i]);
                vis[i] = 1;
                backtrack(res, nums, temp, vis, n);
                temp.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vis(nums.size(), 0), temp;
        backtrack(res, nums, temp, vis, nums.size());
        return res;
    }
};