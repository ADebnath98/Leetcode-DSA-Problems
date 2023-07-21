class Solution {
public:
    pair<int,int> helperMem(vector<int>& nums, int pos, vector<pair<int,int>>& dp){
    int v = 0, c = 1; 
    for(int i=pos+1; i<nums.size(); i++){
        if(nums[pos] < nums[i]){
            if(dp[i].first == -1) dp[i] = helperMem(nums, i, dp); 
            pair<int,int> p = dp[i]; 
            if(p.first > v) {
                v = p.first; c = 0; c+= p.second;  
            }
            else if(p.first == v){
                c += p.second; 
            }
        }
    }
    return {v+1, c}; 
}

int solMem(vector<int>& nums){
    int v = 0, c = 0; 
    vector<pair<int,int>> dp(nums.size()+1, {-1, -1}); 
    for(int i=0; i<nums.size(); i++){
        if(dp[i].first == -1) dp[i] = helperMem(nums, i, dp); 
        pair<int,int> p = dp[i]; 
        if(p.first > v){ v = p.first; c = p.second; }
        else if(p.first == v) {c += p.second; }
    }

    return c; 

}

    int findNumberOfLIS(vector<int>& nums) {
        return solMem(nums); 
    }

};