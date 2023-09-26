class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        set<vector<int>>current;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int lb=j+1;
                int ub=n-1;
                while(lb<ub)
                {
                    long long sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[lb];
                    sum+=nums[ub];
                    if(sum==target)
                    {
                        current.insert({nums[i],nums[j],nums[lb],nums[ub]});
                        lb++;
                        ub--;
                    }
                    else if(sum<target)
                    {
                        lb++;
                    }
                    else
                    {
                        ub--;
                    }
                }
            }
        }
        for(auto it:current)
        {
            result.push_back(it);
        }
        return result;
    }
};

