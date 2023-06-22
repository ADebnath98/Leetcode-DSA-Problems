class Solution {
public:
    int func(vector<int>& prices, int fee, int i, int n, int k, int dp[][2]){
        if(i==n){
            return 0;
        }
        if(dp[i][k]!=INT_MIN){
            return dp[i][k];
        }
        if(k==0){
            return dp[i][k]=max(func(prices,fee,i+1,n,k,dp),-prices[i]-fee+func(prices,fee,i+1,n,1,dp));
        }
        else{
            return dp[i][k]=max(func(prices,fee,i+1,n,k,dp),prices[i]+func(prices,fee,i+1,n,0,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int dp[n][2];
        for(int i=0;i<n;i++){
            dp[i][0]=INT_MIN;
            dp[i][1]=INT_MIN;
        }
        int ans=func(prices,fee,0,n,0,dp);
        return ans;
    }
};