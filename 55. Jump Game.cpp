class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx=nums[0];
        if(nums.size()==0 || nums.size()==1)
        return true;
        for(int i=1;i<nums.size();i++)
        {
            if(mx==0)
            return false;
            if(i==nums.size()-1 && mx>0)
            return true;
            mx=max(mx-1,nums[i]);
        }
        return false;
    }
};