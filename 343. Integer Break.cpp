class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(59);
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        for(int i = 4; i <= n; i++){
            for(int j = 1; j < i; j++){
                int a = j;
                int b = i - j;
                dp[i] = max(dp[i], max(a*b, max(dp[a]*b, max(a*dp[b], dp[a]*dp[b]))));
            }
        }
        return dp[n];
    }
};