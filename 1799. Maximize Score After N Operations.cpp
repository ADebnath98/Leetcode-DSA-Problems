class Solution {
public:

    //gives tle
    int solveMemo(int ind, vector<int> &nums, vector<int> &vis, unordered_map<int,map<vector<int>,int>> dp){
        if(ind == nums.size()/2)
            return 0;

        if(dp.count(ind) && dp[ind].count(vis))
            return dp[ind][vis];

        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(vis[i] == 0 && vis[j] == 0){
                    vis[i] = 1;
                    vis[j] = 1;
                    ans = max(ans, (ind+1)*__gcd(nums[i], nums[j])+solveMemo(ind+1, nums, vis, dp));
                    vis[i] = 0;
                    vis[j] = 0;
                }
            }
        }

        return dp[ind][vis] = ans;
    }

    int solveOpt(int ind, vector<int> &nums, int vis, vector<vector<int>> &dp){
        if(ind == nums.size()/2)
            return 0;

        if(dp[ind][vis] != -1)
            return dp[ind][vis];

        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if((vis & (1<<i)) == 0 && (vis & (1<<j)) == 0){
                    int mask = (vis)|(1<<i);
                    mask = mask|(1<<j);
                    ans = max(ans, (ind+1)*__gcd(nums[i], nums[j])+solveOpt(ind+1, nums, mask, dp));
                }
            }
        }

        return dp[ind][vis] = ans;
    }

    int maxScore(vector<int>& nums) {
        int n = nums.size();
        // unordered_map<int,map<vector<int>,int>> dp;
        // vector<int> visited(n+1, 0);

        // return solveMemo(0, nums, visited, dp);

        vector<vector<int>> dp(n/2 + 1, vector<int>(16384, -1));
        return solveOpt(0, nums, 0, dp);
    }
};