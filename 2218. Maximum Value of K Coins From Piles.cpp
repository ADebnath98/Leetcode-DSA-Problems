class Solution {
public:
    int fun(int i,int k,vector<vector<int>>&piles,vector<vector<int>>&dp)
    {
        if(dp[i][k]>0)
            return dp[i][k];
        if(i==piles.size() || k==0)
            return 0;
        int res=fun(i+1,k,piles,dp),cur=0;
        for(int j=0;j<k && j<piles[i].size();++j)
        {
            cur+=piles[i][j];
            res=max(res,fun(i+1,k-j-1,piles,dp)+cur);
        }
        dp[i][k]=res;
        return res;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,0));
        return fun(0,k,piles,dp);
    }
};