class Solution {
public:
    int helper(int day,int maxDay,vector<int> &days,vector<int> &costs,vector<int> &dp){
        int ind=lower_bound(days.begin(),days.end(),day)-days.begin();
        // ind--;
        if(ind>=days.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        day=days[ind];
        
        return dp[ind]=min({costs[0]+helper(day+1,maxDay,days,costs,dp),costs[1]+helper(day+7,maxDay,days,costs,dp),costs[2]+helper(day+30,maxDay,days,costs,dp)});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int maxDay=days.back();
        int day=days[0];
        vector<int>dp(days.size()+1,-1);
        return min({costs[0]+helper(day+1,maxDay,days,costs,dp),costs[1]+helper(day+7,maxDay,days,costs,dp),costs[2]+helper(day+30,maxDay,days,costs,dp)});
    }
};