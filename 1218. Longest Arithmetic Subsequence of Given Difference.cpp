class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans=1;
        for(int i=0;i<arr.size();i++){
            int temp= arr[i]-difference;
            int tempANS=0;
            if(dp.count(temp)){
                tempANS=dp[temp];
            }
            dp[arr[i]]=1+tempANS;
            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
};