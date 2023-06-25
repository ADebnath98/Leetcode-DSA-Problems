class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> ans(2,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            if(colsum[i]==2)
            {
                if(upper>0 && lower>0)
                {
                    ans[0][i] = 1;
                    ans[1][i] = 1;
                    upper--;
                    lower--;
                }
                else
                return {};
            }
        }
        int cnt1 = 0;
        for(auto &i:colsum)
        {
            if(i==1)
            cnt1++;
        }
        if(upper+lower!=cnt1)
        return {};
        for(int i=0;i<n;i++)
        {
            if(colsum[i]==1)
            {
                if(upper>0)
                {
                    ans[0][i] = 1;
                    ans[1][i] = 0;
                    upper--;
                }
                else if(lower>0)
                {
                    ans[0][i] = 0;
                    ans[1][i] = 1;
                    lower--;
                }
            }
        }
        return ans;
    }
};