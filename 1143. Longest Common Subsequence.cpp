class Solution {
public:
    vector<vector<int>> dp;
    string str1,str2;
    int m,n;
    int longestCommonSubsequence(string text1, string text2) {
        str1 = text1;
        str2 = text2;
        m = text1.size();
        n = text2.size();
        dp = vector<vector<int>>(m,vector<int>(n,-1));
        return sol(0,0);
    }
    int sol(int i, int j) { 
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(str1[i] == str2[j]) 
            dp[i][j] = 1+sol(i+1,j+1);
        else 
            dp[i][j] = max(sol(i+1,j), sol(i,j+1)); 
        return dp[i][j];
    }
};