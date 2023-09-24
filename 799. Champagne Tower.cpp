class Solution {
public:
    double f(int p, int q, int g, vector<vector<double>>& dp, vector<vector<double>>& store){
        if(q<0 || g<0 || g>q) return 0.0;
        if(q==0 and g==0){
            if(p>1){
                store[q][g] = 1;
                return dp[q][g] = (p-1)/2.0;
            }
            store[q][g] = p;
            return dp[q][g] = 0.0;
        }
        if(dp[q][g]!=-1.0) return dp[q][g];
        double t = f(p,q-1,g,dp,store) + f(p,q-1,g-1,dp,store);
        if(t>1){
            store[q][g] = 1;
            return dp[q][g] = (t-1)/2.0;
        }
        store[q][g] = t;
        return dp[q][g] = 0.0;
    }
    double champagneTower(int p, int q, int g) {
        vector<vector<double>> dp(q+1,vector<double>(g+1,-1.0));
        vector<vector<double>> store(q+1,vector<double>(g+1,0));
        f(p,q,g,dp,store);
        return store[q][g];
    }
};