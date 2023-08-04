class Solution {
public:
    int dp[301];
    bool wordBreak(string s, vector<string>& wordDict) {

        sort(wordDict.begin(), wordDict.end());
        memset(dp,0,sizeof dp);
        set<string> st;
        dp[s.length()] = 1;
        for(int i = 0; i < wordDict.size(); i++)
        {
            st.insert(wordDict[i]);
        }
        for(int i = s.length() - 1; i >= 0; i--)
        {
            string temp;
            for(int j = i; j < s.length(); j++)
            {
                temp += s[j];

                //we add !dp[i] condition bcoz if at all 1 subset is found, we do not need any further verification and continue with our operation
                if( !(dp[i]) && st.find(temp) != st.end())
                {
                    //dp[j+1] contains the earlier results 
                    dp[i] = dp[j+1];
                }
            }
        }
        return dp[0];
    }
};