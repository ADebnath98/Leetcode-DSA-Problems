class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n,-1);
        if(k>(n-1)/2) return ans;
        long long sum = 0, i = 0, div = 2*k+1, j = 1;
        while(i<=2*k){ sum += nums[i]; i++; }
        ans[k] = sum/div;
        while(i<n){
            sum += nums[i++];
            sum -= nums[j-1];
            ans[k+j++] = sum/div;
        }
        return ans;
    }
};