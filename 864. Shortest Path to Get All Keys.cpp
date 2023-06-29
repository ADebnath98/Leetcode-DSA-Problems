class Solution {
private:
    struct Node {
        int r, c, mask, keyCnt, steps;
        Node(int _r, int _c, int _mask, int _keyCnt, int _steps): 
            r(_r), c(_c), mask(_mask), keyCnt(_keyCnt), steps(_steps) {}
    };
    inline bool isKey(char c) {
        return c >= 'a' && c <= 'f';
    }
    inline bool isLock(char c) {
        return c >= 'A' && c <= 'F';
    }
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size(), k = 0;
        queue<Node> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isKey(grid[i][j]))  // get number of keys
                    k++;
                else if (grid[i][j] == '@') // get the starting point
                    q.push(Node(i, j, 0, 0, 0));
            }
        }
        bool isVisited[1 << k][m][n];
        for (int i = 0; i < (1 << k); i++)  // set isVisited to false
            for (int j = 0; j < m; j++)
                for (int w = 0; w < n; w++)
                    isVisited[i][j][w] = false;
        int dirs[5] = {-1, 0, 1, 0, -1};
        isVisited[0][q.front().r][q.front().c] = true;
        while (!q.empty()) {
            Node curr = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nxtR = curr.r + dirs[i], nxtC = curr.c + dirs[i + 1];
                if (nxtR >= 0 && nxtR < m && nxtC >= 0 && nxtC < n &&
                    grid[nxtR][nxtC] != '#' && !isVisited[curr.mask][nxtR][nxtC]) { // check if it's valid
                        char c = grid[nxtR][nxtC];
                        if (isLock(c) && (curr.mask & (1 << (c - 'A'))) == 0)   // lock but no key
                            continue;
                        isVisited[curr.mask][nxtR][nxtC] = true;
                        if (isKey(c) && (curr.mask & (1 << (c - 'a'))) == 0) { // key and not picked yet
                            if (curr.keyCnt == k - 1)   // next is the last key
                                return curr.steps + 1;
                            q.push(Node(nxtR, nxtC, 
                                curr.mask | (1 << (c - 'a')), curr.keyCnt + 1, curr.steps + 1));
                        }
                        else
                            q.push(Node(nxtR, nxtC, 
                                curr.mask, curr.keyCnt, curr.steps + 1));
                    }
            }
        }
        return -1;
    }
};