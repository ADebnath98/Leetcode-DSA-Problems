class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long tot = 0;
        for(auto x:nums) {
            tot += (long long)x;
        }

        long long req = tot - x;
        int i = 0; int j = 0;
        int ans = 0; int curr = 0;
        
        if(req == 0) {
            return n;
        }

        while(i<n && j<n) {
            curr += (long long) nums[j];
            while(curr > req && i<j) {
                curr -= (long long)nums[i];
                i++;
            }
            if(curr == req) {
                ans = max(ans,j-i+1);
            }
            j++;
        }
        
        if(ans == 0) {
            return -1;
        }

        return n-ans;
    }
};