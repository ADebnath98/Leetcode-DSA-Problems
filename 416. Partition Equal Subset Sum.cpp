class Solution {
public:
    int HalfSumPresent(int i,vector<int>&arr, int sum,vector<vector<int>>&dp)
    {
        if(sum==0) return 1;
        if(i>=arr.size()) return 0;
        if(sum<0) return 0;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        return dp[i][sum]=HalfSumPresent(i+1,arr,sum-arr[i],dp) or HalfSumPresent(i+1,arr,sum,dp);
    }

    bool canPartition(vector<int>& arr) {
                int sum=0;
        for(int i=0;i<arr.size();i++) sum+=arr[i];
        
        if(sum&1 ) return 0;
        vector<vector<int>>dp(arr.size()+1, vector<int>(sum+1,-1));
        
        return HalfSumPresent(0,arr,sum/2,dp);
    }
};