class Solution {
    int m,n;
    vector<vector<bool>> visited;
    enum Dir {left, down, right, up};

    bool canMove(int r, int c, Dir dir) {
        return (dir == left and c < n - 1 and !visited[r][c + 1]) or
                (dir == down and r < m - 1 and !visited[r + 1][c]) or
                (dir == right and 0 < c and !visited[r][c - 1]) or
                (dir == up and 0 < r and !visited[r - 1][c]);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size(); 
        n = matrix[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n));

        int limit = m * n, r = 0, c = 0;
        Dir dir = left;

        vector<int> answer;
        for (int i = 0; i < limit; i++) {
            answer.push_back(matrix[r][c]);
            visited[r][c] = true;
            switch(dir) {
                case left:
                    if (canMove(r, c, left)) {
                        c++;
                    } else {
                        r++;
                        dir = down;
                    }
                break;
                case down:
                    if (canMove(r, c, down)) {
                        r++;
                    } else {
                        c--;
                        dir = right;
                    }
                break;
                case right:
                    if (canMove(r, c, right)) {
                        c--;
                    } else {
                        r--;
                        dir = up;
                    }
                break;
                case up:
                    if (canMove(r, c, up)) {
                        r--;
                    } else {
                        c++;
                        dir = left;
                    }
                break;
            }
        }
        return answer;
    }
};