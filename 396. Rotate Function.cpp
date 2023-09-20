class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        int newans = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            newans += (nums[i]*i);
        }
        int l = 1, r;
        int ans = newans;
        while(l < n){
            int r = n+l-1;
            int add_item = nums[r%n]*r;
            int remove = (l-1) * nums[l-1];
            newans = newans - remove + add_item - sum;
            ans = max(ans , newans);
            l++;
        }
        return ans;
    }
};