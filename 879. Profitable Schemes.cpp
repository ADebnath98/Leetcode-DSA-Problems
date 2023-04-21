class Solution {
public:
    const int MOD = (int) 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profits) {
        int K = group.size();
        int dp[K + 1][n + 1][minProfit + 1];
        memset(dp, 0, sizeof(dp));
        for(int count = 0; count <= n; count++) {
            dp[K][count][minProfit] = 1;
        }
        for(int idx = K - 1; idx >= 0; idx--) {
            for(int count = 0; count <= n; count++) { // count
                for(int profit = 0; profit <= minProfit; profit++) {
                    dp[idx][count][profit] = dp[idx + 1][count][profit];
                    if(count + group[idx] <= n) {
                        dp[idx][count][profit] += dp[idx + 1][count + group[idx]][min(minProfit, profit + profits[idx])];
                        dp[idx][count][profit] %= MOD;
                    }
                }
            }
        }
        return dp[0][0][0];
    }
};