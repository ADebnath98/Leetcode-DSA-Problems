class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();

        vector<int> dp(n,0);
        vector<int> dpprevious(n,0);
        for(int i=n-1; i>-1;i--){
            dp[i]=1;
            for(int j=i+1;j<n;j++){
                if(s[j]==s[i]){
                    dp[j]=dpprevious[j-1]+2;
                }
                else{
                    dp[j]=max(dp[j-1],dpprevious[j]);
                }
            }
            dpprevious=dp;

        }
        return dp[n-1];
        
    }
};