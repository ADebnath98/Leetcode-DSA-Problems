class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        for(int i = n-2 ; i >= 0 ; i--){
            int j = i + 1;
            while(ans[j] && temperatures[j] <= temperatures[i]){
                j = j + ans[j];
            }
            if(temperatures[j] > temperatures[i])
                ans[i] = j - i;
        }
        return ans;
    }
};