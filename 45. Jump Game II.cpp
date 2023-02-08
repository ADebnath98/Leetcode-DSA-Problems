class Solution {
public:
    int jump(vector<int>& nums) {
        int count=0,maxi=0,temp=0;
        for(int i=0;i<nums.size()-1;i++){
            maxi=max(maxi,nums[i]+i);
            if(i==temp){
                temp=maxi;
                count++;
            }
        }
        return count;
    }
};