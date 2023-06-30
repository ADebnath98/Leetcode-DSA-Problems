Intuition
This problem can be solved by Breadth-First Search (BFS) and Binary Search, where we search for the last day we can walk from the top to the bottom (I will use "walk out" instead). We can search for it because we can definitely walk out as every cell is land at first, but someday, we will be unable to walk out again. (We will find the last true in a monotonic function)

Noted that there is a faster solution using Disjoint-set Union (DSU).

Approach
In order to use BFS, we first set a new array (a[][]): each cell is a date that changes from land to water.

On d day, land and water are greater and lesser than d, respectively.

Here are what's going on during a Binary Search:

On mid day, we check whether we can walk out by using BFS.
Before BFS, we push every top cell that is land.
During BFS, if a current cell is the bottom, we can break the loop as it means we can walk out.
If we can, it means we can also walk out on all the previous days. So, we can skip all of them by shifting l up.
If we can't, it means we can't also walk out on all the next days. So, we can skill all of them by shifting r down.
You can follow my step-by-step code below.

Complexity
Time complexity: O(row⋅col⋅log⁡(row⋅col))O(row\cdot col\cdot \log(row\cdot col))O(row⋅col⋅log(row⋅col))
Space complexity: O(row⋅col)O(row\cdot col)O(row⋅col)'


class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int N = row + 5, M = col + 5;
        int a[N][M], dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
        bool vis[N][M];
        // set date to each cell
        for(int i = 0; i < cells.size(); i++)
            a[cells[i][0]][cells[i][1]] = i+1;
        // binary search
        int l = 0, r = row * col;
        while(l < r){
            int mid = (l+r+1) / 2;
            bool check = false;
            fill_n(vis[0], N*M, false);
            queue<pair<int,int>> q;
            // push the top cells
            for(int i = 1; i <= col; i++)
                if(a[1][i] > mid)
                    q.push({1,i});
            // BFS
            while(!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                if(vis[x][y]) continue;
                vis[x][y] = true;
                // check if a current cell is the bottom
                if(x == row){
                    check = true;
                    break;
                }
                for(int i = 0; i < 4; i++){
                    int xx = x + dx[i], yy = y + dy[i];
                    if(xx > row || xx < 1 || yy < 1 || yy > col || vis[xx][yy] || a[xx][yy] <= mid) continue;
                    q.push({xx,yy});
                }
            }
            if(check) l = mid;
            else r = mid-1;
        }
        return r;
    }
};