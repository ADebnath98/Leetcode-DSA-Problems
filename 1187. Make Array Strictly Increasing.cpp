Intuition
Question of DP as we know for any index i whether we need to repalce it or not . Knapsack type .
And the ordering of nums 2 is not important because we can take any number from nums2 so we will sort it (Greedy). As we will be needing the number just greater than teh previous one .
For any index i :
I have two option

nums[i]>nums[i-1] : (i) I will not replace it and move further
(ii) I will replace it with the number just greater than nums[i-1]
nums[i]<=nums[i-1] : Here it is mandatory to repalce it with the number just greater than the previous number .
We will simply apply it
I have inserted -1 in both num1 and nums2 in start so that we can satrt our index with 1 and will save from the 0 index operation
dp[i][j] : Minimum operation required to make array increasing i am at index i .




class Solution {
public:
    long long  Recursion(vector<int>& nums1 , vector<int>& nums2 , int i , int j ,vector<vector<int>> &dp )
    {
        if(i>=nums1.size())
        {
            return 0;
        }
        if(j>=nums2.size())
        {
            while(i<nums1.size())
            {
                if(nums1[i]<=nums1[i-1])
                {return INT_MAX ;}
                i++;
            }
            if(i==nums1.size())
            {
                return 0;
            }
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        long long int mini =INT_MAX; 
        int k = i;
        for( ;k<nums1.size() ;k++)
        {
            if(nums1[k]==nums2[j] && nums1[k]>nums1[k-1])
            {
                j++;
                continue;
            }
            auto it = lower_bound(nums2.begin()+j, nums2.end() , nums1[k-1]+1);
            int ind = it-nums2.begin() ;
            if(ind!=nums2.size())
            {
                int temp = nums1[k];
                // Changes in array 
                nums1[k]= nums2[ind];
                long long b = 1+Recursion(nums1 , nums2 , k+1 , ind+1, dp ) ;
                mini = min(b , mini);
                // restoring the changes 
                nums1[k] = temp ;
            }
            if(nums1[k]<=nums1[k-1])
            {
                break ;
            }
        }
        if(k==nums1.size())
        {
            mini =0;
        }
        return dp[i][j] = mini;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        arr1.insert(0+arr1.begin(),-1);
        arr2.insert(0+arr2.begin(),-1);
        sort(arr2.begin(),arr2.end());
        vector<vector<int>> dp(arr1.size()+1 , vector<int>(arr2.size()+1, -1)) ;
        long long ans = Recursion(arr1 , arr2 , 1,1 , dp);
        if(ans>1e9)
        {
            return -1;
        }
        return ans ;
    }
};