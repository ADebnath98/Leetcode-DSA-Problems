class Solution {
public:    

    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.length();
        map<string, int>mpp;
        for(auto &it:dictionary){
            mpp[it]++;
        }
        vector<int>dp(n+1, 0);
        for(int idx=n-1; idx>=0; idx--){
            int mini=n;
            string curString="";
            for(int i=idx; i<n; i++){
                curString+=s[i];
                int curExtra=0;
                if(mpp.find(curString)==mpp.end()){
                    curExtra=curString.length();
                }
                int remExtra=dp[i+1];
                int totExtra=curExtra+remExtra;
                mini=min(mini, totExtra);
            }
            dp[idx]=mini;
        }
        return dp[0];
    }
};