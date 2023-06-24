class Solution {
public:
    int helper(int index,int dif,vector<int>&rods,vector<vector<int>>&dp){
        int n= rods.size();
        if(index==n){
            if(dif==0) return 0;
            return INT_MIN;
        }
        if(dp[index][dif+5000]!=-1) return dp[index][dif+5000];
        int option1= helper(index+1,dif,rods,dp);
        int option2= helper(index+1, dif-rods[index],rods,dp);
        int option3= rods[index]+helper(index+1,dif+rods[index],rods,dp);
        return dp[index][dif+5000]=max(option1,max(option2,option3));
    }
    int tallestBillboard(vector<int>& rods) {
        int n= rods.size();
        vector<vector<int>>dp(n,vector<int>(10001,-1));
        return helper(0,0,rods,dp);
        
    }
};