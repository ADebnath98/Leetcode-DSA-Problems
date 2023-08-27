class Solution {
public:
    bool solve(int index, int k, vector<int>&stones, vector<vector<int>>&dp){
        if(index == stones.size() - 1)return true;
        if(dp[index][k]!=-1){return dp[index][k];}
        for(int i=k+1;i>=k-1;i--){
            for(int j=i;j>=1;j--){
                if(index + j < stones.size() && stones[index] + i == stones[index + j]){
                    if(solve(index + j, i, stones, dp)==true){
                        return dp[index][k]  = true;
                    }
                }
            }
        }
        return dp[index][k] = false;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]>1)return false;
        vector<vector<int>>dp(stones.size(),vector<int>(2005,-1));
        return solve(1, 1, stones, dp);
    }
};