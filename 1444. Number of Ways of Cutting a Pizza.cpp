Intuition
we have two choices -

we can cut horizontaly
we can cut verticaly
so what I am doing is traversing the row from 0 to n-2 and try to cut it.
similarly traversing the column from 0 to m-2 and try to cut it.
Try to cut it means if that particulat section which i am tryinh to cut whether that contains at least one A or not if this satisfies then only I include that into my answer.

Approach
Complexity
Time complexity:
O(N*M)

Space complexity:
O(N + M)

Code
class Solution {
public:
    int mod = int(1e9+7);

    bool isOkayhz(int s,int row, int col, vector<string> &pizza)
    {
        int m = pizza[0].size();
        for(int j=s;j<=row;j++)
        {
            for(int i=col;i<m;i++) {
                if(pizza[j][i] == 'A') return true;
            }
        }
        return false;
    }

    bool isOkayvt(int row, int s, int col, vector<string> &pizza)
    {
        int n = pizza.size();
        for(int i=row;i<n;i++) {
            for(int j=s;j<=col;j++) {
                if(pizza[i][j] == 'A') return true;
            }
        }
        return false;
    }

    bool isOkayRest(int row, int col, vector<string> &pizza)
    {
        for(int i=row;i<pizza.size();i++)
        {
            for(int j=col;j<pizza[0].size();j++)
            {
                if(pizza[i][j] == 'A') return true;
            }
        }
        return false;
    }

    int f(int i, int j, vector<string>& pizza, int k, vector<vector<vector<int>>>& dp)
    {
        if(i<0 || i>=pizza.size() || j<0 || j>=pizza[0].size() || k<0) return 0;
        if(k == 0) {
            if(isOkayRest(i,j,pizza)) return 1;
            return 0;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];

        int hz = 0;
        for(int row=i;row<pizza.size()-1;row++)
        {
            bool flaghz = isOkayhz(i,row,j,pizza);
            if(flaghz) {
                hz = (hz%mod + f(row+1, j, pizza, k-1, dp)%mod)%mod;
            }
        }

        int vt = 0;
        for(int col=j;col<pizza[0].size()-1;col++)
        {
            bool flagvt = isOkayvt(i, j, col, pizza);
            if(flagvt) {
                vt = (vt%mod + f(i, col+1, pizza, k-1, dp)%mod)%mod;
            }
        }

        return dp[i][j][k] = (hz%mod + vt%mod)%mod;
    }

    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return f(0, 0, pizza, k-1, dp);
    }
};