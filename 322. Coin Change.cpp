class Solution {
public:
    // int solve(vector<int>&coins,int amount){
    //     //base case
    //     if(amount==0){
    //         return 1;
    //     }
    //     if(amount<0){
    //         return INT_MAX;
    //     }

    //     int mini=INT_MAX;
    //     for(int i=0;i<coins.size();i++){
    //          int ans=solve(coins,amount-coins[i]);
    //          if(ans!=INT_MAX){
    //           mini=min(ans,mini);
    //          }
    //     }
    //     return mini;
    // }

//  int coinChange(vector<int>& coins, int amount) {
    //     //int index=0;
    //    int ans= solve(coins,amount);
    //    if(ans==INT_MAX)
    //        return -1;


    int Memoization(vector<int> &dp, vector<int> &coins, int amount)
       	    {
           
       	        if (amount == 0)
                
       	            return 0;
       	        if (amount < 0)
                
       	            return INT_MAX;
       	        if (dp[amount] != -1)
               
       	            return dp[amount];
       	        int mini = INT_MAX;
       	        for (int i = 0; i < coins.size(); i++)
       	        {
       	            int res = Memoization(dp, coins, amount - coins[i]);
                   
       	            if (res != INT_MAX)
                    
       	                mini = min(mini, res + 1);
       	        }
       	        return dp[amount] = mini;
       	    }
       	int coinChange(vector<int> &coins, int amount)
       	{
       	    vector<int> dp(amount + 1, -1);
       	    int ans = Memoization(dp, coins, amount);
       	    if (ans == INT_MAX)
       	        return -1;
            
       	    else
       	        return ans;
       	}

    
};