class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++){
            if(nums[i]<=0) continue;
            else if(i<n-1 and nums[i]==nums[i+1]) continue;
            else{
                if(ans==nums[i]){
                    ans=ans+1;
                }
                else return ans;
            }
        } 
        return nums[n-1]<=0?1:nums[n-1]+1;
    }
};