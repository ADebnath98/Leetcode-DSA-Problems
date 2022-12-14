class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();int i=n;
        int sum=nums[--i],curr_sum=0,prev_sum=0,l=n;
        while(i--){
            curr_sum=prev_sum+nums[i];
            prev_sum=sum;
            sum=max(sum,curr_sum);
            
        }
        return sum;
    }
};