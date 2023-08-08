class Solution {
private:
    int getPivot(vector<int>& nums, int n)
    {
        int s = 0, e = n-1;
        while (s < e)
        {
            int mid = (s + e)/2;
            if (nums[mid] >= nums[0])
            {
                s = mid + 1;
            }
            else 
            {
                e = mid;
            }
        }
        return s;
    }
    int binarySearch(vector<int>& nums, int target, int low, int high)
    {
        int ans = -1;
        while ( low <= high )
        {
            int mid = (low + high)/2;
            if (nums[mid] == target) 
            {
                ans = mid;
            }
            if (nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int piv = getPivot(nums, n);

        if (target <= nums[n-1] && target >= nums[piv])
        {
            return binarySearch(nums, target, piv, n - 1);
        }
        else
        {
            return binarySearch(nums, target, 0, piv-1);
            
        }
        
        
    }
};