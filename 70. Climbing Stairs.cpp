class Solution {
public:
    int dp[50];
    
    int func(int n)
    {
        int c= 0;
        if(n == 2)
        {
            return 2;
        }
        if(n == 1)
        {
            return 1;
        }
        if(dp[n] != -1)return dp[n];
        
        
        c = c + func(n-1);
        c = c + func(n-2);
        
        return dp[n] = c;
        
        
    }
    
    
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return func(n);
    }
};