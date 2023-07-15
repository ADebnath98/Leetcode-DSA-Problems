class Solution {
public:
    int helper(vector<vector<int>>& events, int k,vector<vector<int>> &dp,int i){
        int n=events.size();
        if(k==0||i==events.size()) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int nextEvent=n;
        for(int j=i+1;j<n;j++){
            if(events[j][0]>events[i][1]){
                nextEvent=j;
                break;
            }
        }
        return dp[i][k]=max((helper(events,k-1,dp,nextEvent)+events[i][2]),helper(events,k,dp,i+1));
    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        sort(events.begin(),events.end());
        return helper(events,k,dp,0);
    }
};