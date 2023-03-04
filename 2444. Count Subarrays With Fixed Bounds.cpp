class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int preMin=-1, preMax=-1, preValid=-1;
        long long ans=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>=minK && nums[i]<=maxK){
                if(nums[i]==minK) preMin=i;
                if(nums[i]==maxK) preMax=i;
                if(preMin!=-1 && preMax!=-1){
                    ans+=min(preMin,preMax)-preValid;
                }
            }
            else{
                preValid=i;
                preMin=-1;
                preMax=-1;
            }
        }
        return ans;
    }
};