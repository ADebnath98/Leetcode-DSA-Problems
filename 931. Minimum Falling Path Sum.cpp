class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=r?matrix[0].size():0;
        int ans=INT_MAX;
        if(r==0 || c==0)
            return 0;
        for(int i=1;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int m=matrix[i-1][j];
                if(j>0)
                    m=min(m,matrix[i-1][j-1]);
                if(j<c-1)
                    m=min(m,matrix[i-1][j+1]);
                matrix[i][j]+=m;
            }
        }
        for(int k=0;k<c;k++)
        {
            ans=min(ans,matrix[r-1][k]);
        }
        return ans;
    }
};