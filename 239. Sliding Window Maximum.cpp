class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>p;
        int i=0,j=0,n=nums.size();
        while(j<n)
        {
            p.push(make_pair(nums[j],j));
            if(j-i+1==k)
            {
                while(p.top().second<i)
                    p.pop();
                if(p.top().second==i)
                {
                    ans.emplace_back(p.top().first);
                    p.pop();
                }
                else
                    ans.emplace_back(p.top().first);
                i++;
            }
            j++;
        }
        return ans;
    }
};
