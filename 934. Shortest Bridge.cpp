class Solution {
    int delRow[4]={-1, 0, 1, 0};
    int delCol[4]={0, 1, 0, -1};
    queue<pair<int,pair<int,int>>>q;
private:

    // dfs to mark find edgenodes
    void f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&vis)
    {
        int n = grid.size();

        vis[i][j]=1;
        grid[i][j]=0;

        for(int k=0; k<4; k++)
        {
            int nrow = i + delRow[k];
            int ncol = j + delCol[k];

            if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and !vis[nrow][ncol])
            {
                if(grid[nrow][ncol]==0)q.push({0, {i,j}});
                else f(nrow,ncol, grid, vis);
            }
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(n, 0));
        int sr = -1, sc=-1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    sr=i;
                    sc=j;
                    break;
                }
            }
        }

        f(sr,sc,grid,vis);

        // bfs to get to the next island.
        while(!q.empty())
        {
            auto it = q.front();
            int row = it.second.first;
            int col = it.second.second;
            int step = it.first;
            q.pop();

            if(grid[row][col]==1)
            {
                return step-1; // this will obviously be the shortest one as we are traversing level wise and the first occurence is returned.
            }

            for(int i=0; i<4; i++)
            {
                int nrow=row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    q.push({step+1,{nrow, ncol}});
                }
            }
        }
        return -1;
    }
};