class Solution {
    void dfs(int i, vector<int> &nums, vector<int> &v, set<vector<int>> &s) {
        if(v.size() > 1) s.insert(v);
        if(i == nums.size()) return;
        
        for(int j=i; j<nums.size(); j++) {
            if(v.size() && v.back() > nums[j]) continue;
            v.push_back(nums[j]);
            dfs(j + 1, nums, v, s);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> v;
        set<vector<int>> s;

        dfs(0, nums, v, s);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};