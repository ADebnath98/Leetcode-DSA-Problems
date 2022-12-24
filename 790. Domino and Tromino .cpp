class Solution {
public:
    int numTilings(int n) {
        int mod=1000000007;
        long long dp[n+1];
        if(n==2||n==1)return n;
        dp[1]=1,dp[2]=2,dp[3]=5;
        if(n<=3)return dp[n];
        for(int i=4;i<=n;i++){
            dp[i]=2*dp[i-1]+dp[i-3];
            dp[i]=dp[i]%mod;
        }
        return dp[n];
    }
};