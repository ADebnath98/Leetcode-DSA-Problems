class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-1;){
            if(nums[i]==nums[i+1]){
                i=i+3;
            }
            else 
            return nums[i];
        }
        return nums[nums.size()-1];
    }
};