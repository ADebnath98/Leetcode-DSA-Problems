class Solution {
public:
    int dp[501][501];
    int helper(int ind, vector<int>& cost, vector<int>& time, int x, int n){
        if(x <= 0)
            return 0;
        if(ind == n)
            return 1e9;
        if(dp[ind][x] != -1)
            return dp[ind][x];
        int mini = 1e9;
        mini = min(mini, cost[ind] + helper(ind + 1, cost, time, x - (time[ind] + 1), n));
        mini = min(mini, helper(ind + 1, cost, time, x, n));
        return dp[ind][x] = mini;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = time.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, cost, time, n, n);
    }
};


- Time complexity:
O(n ^ 2)

- Space complexity:
O(n ^ 2)