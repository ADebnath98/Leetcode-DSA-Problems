class Solution {
public:
    int helper(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(i==s1.size() || j==s2.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=(int)s1[i]+helper(s1,s2,i+1,j+1,dp);
        return dp[i][j]=max(helper(s1,s2,i+1,j,dp),helper(s1,s2,i,j+1,dp));
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        int ans=0;
        for(int i=0;i<s1.size();i++)ans+=(int)s1[i];
        for(int i=0;i<s2.size();i++)ans+=(int)s2[i];
        ans-=2*helper(s1,s2,0,0,dp);
        return ans;
    }
};