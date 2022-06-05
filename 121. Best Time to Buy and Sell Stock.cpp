class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_Price = prices[0];
        int profit = 0;
        
        for(int i=1; i<prices.size(); i++){
            if(prices[i] < curr_Price)      
                curr_Price = prices[i];
            else{    
                if(prices[i]-curr_Price > profit)
                    profit = prices[i] - curr_Price;
            }
        }
        
        return profit;
    }
};