class Solution {
public:
    void util(int i,int j,vector<vector<int>>& grid,int &count)
    {
        if(i<0 || i>grid.size()-1 || j<0 || j>grid[0].size()-1 || grid[i][j]==-1)return;
        bool co=true;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==0){
                    co=false; break;
                }
            }
        }
        if(grid[i][j]==2 && co){
            count++; return;
        }
        else if(grid[i][j]==2)return;
        grid[i][j]=-1;
        util(i+1,j,grid,count);
        util(i-1,j,grid,count);
        util(i,j+1,grid,count);
        util(i,j-1,grid,count);
        grid[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==1)
        util(i,j,grid,count);
        }
        return count;
    }
};