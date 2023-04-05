class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long res=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            res=max(res,(sum+i)/(i+1));
        }
        return res;
    }
};