Approach
Here i have used Co-ordinate shift like we do in case of finding Length of longest increasing subsequence.
Also use array or vector instead of map or unordered_map.


Complexity
Time complexity: O(N2)O(N^2)O(N 
2
 ) where N = nums.length
Space complexity: O(N2)O(N^2)O(N 
2
 )





class Solution {
    int longestArithSeqLengthHelp(int ind, int pre, vector<vector<int>> &dp, vector<int>& nums, vector<vector<int>> &mpp) {
        if(ind == nums.size()) return 0;
        if( dp[ind][pre] != -1) return dp[ind][pre];

        int ans = 1;
        if( pre == 0 ){
            ans = max(ans, longestArithSeqLengthHelp(ind+1, 0, dp, nums, mpp));
            for(int i=ind+1; i<nums.size(); i++) 
                ans = max(ans, 1+longestArithSeqLengthHelp(i, ind+1, dp, nums, mpp)); 
        }else{
            // take current element if possible
            int d = nums[ind] - nums[pre-1], t = mpp[ind][500+d];
            if( t != -1) ans = 1 + longestArithSeqLengthHelp(t, ind+1, dp, nums, mpp);
        }
        return dp[ind][pre] = ans;        
    }

public:
    // Top Down
    int longestArithSeqLength1(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+2, -1));
        vector<vector<int>> mpp(n+1, vector<int>(1005, -1));
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int d = nums[j] - nums[i];
                if( mpp[i][500+d] == -1 ) mpp[i][500+d] = j;
            }
        }

        return longestArithSeqLengthHelp(0, 0, dp, nums, mpp);
    }


    // Bottom Up
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+2, 0));
        vector<vector<int>> mpp(n+1, vector<int>(1005, -1));
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int d = nums[j] - nums[i];
                if( mpp[i][500+d] == -1 ) mpp[i][500+d] = j;
            }
        }

        for(int ind=n-1; ind>=0; ind--){
            for(int pre=n; pre>=0; pre--){
                int ans = 1;
                if( pre == 0 ){
                    ans = max(ans, dp[ind+1][0]);
                    for(int i=ind+1; i<nums.size(); i++) 
                        ans = max(ans, 1+dp[i][ind+1]); 
                }else{
                    // take current element if possible
                    int d = nums[ind] - nums[pre-1], t = mpp[ind][500+d];
                    if( t != -1) ans = 1 + dp[t][ind+1];
                }
                dp[ind][pre] = ans;   
            }
        }

        return dp[0][0];
    }
};