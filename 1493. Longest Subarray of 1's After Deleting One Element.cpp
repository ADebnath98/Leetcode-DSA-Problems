class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int curr=0, prev=0, ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                curr++;
            }
            else{
                ans= max(ans, prev+curr);
                prev=curr;
                curr=0;
            }
        }
        ans= max(ans, prev+curr);

        if(ans == nums.size())
            return ans-1;
        else
            return ans;
    }
};