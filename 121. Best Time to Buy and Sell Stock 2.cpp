class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<mini) mini = prices[i];
            if(profit<prices[i]-mini) profit = prices[i]-mini;
        }
        return profit;
    }
    
};