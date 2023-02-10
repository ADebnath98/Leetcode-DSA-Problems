class Solution {
public:
    const int dx[4] = {-1,1,0,0};
    const int dy[4] = {0,0,-1,1};
    int maxDistance(vector<vector<int>>& grid) {
        int c = grid[0].size();
        int r = grid.size();
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j] = 2;
                }
            }
        }
        if(q.size() == r*c || q.empty())
            return -1;
        int count=0; int maxi=0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int next_i = node.first + dx[i];
                    int next_j = node.second + dy[i];
                    if(next_i>=0 && next_j>=0 && next_i<r && next_j<c){
                        if(grid[next_i][next_j]==0){
                            grid[next_i][next_j] = 2; //visited
                            q.push({next_i, next_j});
                        }
                    }
                }
            }
            maxi++;
        }
        return maxi-1;
    }
};