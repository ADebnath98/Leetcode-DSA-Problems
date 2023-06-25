class Solution {
    int m=1e9+7;
    int workfunc(vector<int>& locations, int start, int finish, int fuel,vector<vector<int>> &dp)
    {
        // if fuel is less than 0 then we can't travel to further location
        if(fuel<0) return 0;

        if(fuel==0)
        {
            // if fuel is 0 and we reach to the finishing location
            if(start==finish) return 1;
            else return 0;
        }
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        int ans=0;
        for(int i=0;i<locations.size();i++)
        {
            if(start!=i)
            {
                ans=(ans+workfunc(locations,i,finish,fuel-abs(locations[i]-locations[start]),dp))%m;
            }
        }
        if(start==finish) ++ans;
        return dp[start][fuel]=ans;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(),vector<int>(fuel+1,-1));
        return workfunc(locations,start,finish,fuel,dp);
    }
};