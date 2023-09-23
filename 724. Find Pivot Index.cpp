class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        vector<int>v(nums.size(),0);
        v[0] = nums[0];

        for(int i =1;i<nums.size();i++){

            v[i] = v[i-1]+nums[i];
        }
        int n = nums.size()-1;
        for(int i =0;i<nums.size();i++){

            if(i==0){
                if(v[n]-v[0] ==0)
                return 0;
            }
            else if(i==n)
            {
                if(v[n-1] ==0)
                return n;
            }
            else
            {
                if(v[i-1]==v[n]-v[i])
                return i;
            }
        }
        return -1;
    }
};