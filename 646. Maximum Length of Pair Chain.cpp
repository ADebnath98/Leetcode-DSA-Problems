class Solution {
public:
    int solve(int index,vector<vector<int>>&v,vector<int>&dp){
        if(dp[index]!=-1) return dp[index];
        int last=v[index][1];
        int res=0;
        for(int i=index+1;i<v.size();i++){
            if(v[i][0]>last) res=max(res,1+solve(i,v,dp));
        }
        return dp[index]=res;
    }
    int findLongestChain(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        int n=v.size();
        vector<int> dp(n,-1);
        int k=0;
        for(int i=0;i<n;i++){
            k=max(solve(i,v,dp),k);
        }
        return k+1;
    }
};