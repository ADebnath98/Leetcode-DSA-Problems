class Solution {
public:
int solve(int i, int j, vector<int>&a, vector<int>&b,vector<vector<int>>&dp){
    if(i >= a.size() || j >= b.size()) return INT_MIN;
    if(dp[i][j] != INT_MIN) return dp[i][j];
    int op1 = (a[i]*b[j]) + max(solve(i+1,j+1,a,b,dp),0);
    int op2 = max(solve(i+1,j,a,b,dp),solve(i,j+1,a,b,dp));
    return dp[i][j] = max(op1,op2);
}
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,INT_MIN));
        return solve(0,0,nums1,nums2,dp);
    }
};