class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
     
        int n=cost.size();
        vector<int>dp(n+2,0);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int idx=2;idx<n;idx++){
            dp[idx] = cost[idx] + min(dp[idx-1],dp[idx-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
};

//TC:O(N)
//SC:O(N)