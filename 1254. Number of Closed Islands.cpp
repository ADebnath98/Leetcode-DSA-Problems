class Solution {
public:

    void dfs(vector<vector<int>>&grid, int i, int j, int &m, int &n, vector<vector<bool>>&vis, bool &touchingBorder){
        //preceed if land and not visited
        if(grid[i][j] == 1 || vis[i][j])
            return;

        //set visited
        vis[i][j] = true;

        //set touchingBorder
        if(i==0 || j==0 || i==m-1 || j==n-1)
            touchingBorder=true;

        //call dfs recursively if within grid
        if(j+1 < n) dfs(grid,i,j+1,m,n,vis,touchingBorder);
        if(i+1 < m) dfs(grid,i+1,j,m,n,vis,touchingBorder);
        if(j-1 >= 0) dfs(grid,i,j-1,m,n,vis,touchingBorder);
        if(i-1 >= 0) dfs(grid,i-1,j,m,n,vis,touchingBorder);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        bool touchingBorder = false;
        int res=0;
        vector<vector<bool>> vis(m, vector<bool>(n,false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    touchingBorder = false;
                    dfs(grid,i,j,m,n,vis,touchingBorder);

                    if(!touchingBorder){
                        res++;
                    }
                        
                }
            }
        }

        return res;

    }
};