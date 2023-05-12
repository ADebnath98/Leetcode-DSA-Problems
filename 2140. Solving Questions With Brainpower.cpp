class Solution {
private: 
    long long helper(vector<vector<int>>& questions,int i,vector<long long>&dp){
        if(i >= questions.size()) return 0;
        if(dp[i] != -1) return dp[i];

        long long take = questions[i][0] + helper(questions,i + questions[i][1] + 1,dp);
        long long notTake = helper(questions,i+1,dp);

        return dp[i] = max(take,notTake);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return helper(questions,0,dp);
    }
};