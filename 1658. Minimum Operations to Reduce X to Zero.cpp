class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n = nums.size();
        unordered_map<int, int> m;
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            m[sum] = i;
        }
        int t = sum - x;
        sum = 0;
        if(t<0)
            return -1;
        int res = INT_MIN;
        m[0] = -1;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            if(m.find(sum - t) != m.end()){
                res = max(res, i -m[sum - t]);
            }
        }
        return res == INT_MIN?-1:n - res;
        
        
    }
};