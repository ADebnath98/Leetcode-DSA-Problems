class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        if(grid[0][0]==1)return-1;
        if(grid[0][0]==0&&m==1&&n==1)return 1;

        q.push({{0,0},1});
        vector<vector<int>>vis(n,vector<int>(m,0));
        while(!q.empty()){
        int x=q.front().first.first;
        int  y=q.front().first.second;
        int a=q.front().second;
        q.pop();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int nr=x+i;
                int nc=y+j;
                if(nr>=0&&nc>=0&&nr<n&&nc<m&&vis[nr][nc]==0&&grid[nr][nc]==0){
                    if(nr==n-1&&nc==m-1)return a+1;
                    vis[nr][nc]=1;
                    q.push({{nr,nc},a+1});

                }
            }
        }
        }
        return -1;
    }
};