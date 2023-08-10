class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int mid;
         while (i<j and nums[i] == nums[i+1])
         {
             i+=1;
         }
        
        while (i<j and nums[j] == nums[j-1])
        {
            j-=1;
        }
        while(i <= j)
        {
            mid = i + (j-i)/2 ;
            if(t == nums[mid])
            {
                return true;
            }
            else if(nums[i] <= nums[mid])
            {
                if(t >= nums[i] && t < nums[mid])
                {
                    j = mid-1;
                }
                else
                {
                    i = mid + 1;
                }
            }
            else if(nums[j] >= nums[mid])
            {
                if(t > nums[mid] && t <= nums[j])
                {
                    i = mid + 1;
                }
                else
                {
                    j = mid - 1;
                }
            }
        }
        return false;
    }
};