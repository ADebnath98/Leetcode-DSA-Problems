class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0, n = grid[0].size(), index = n - 1;
        for (auto row : grid) {
            while (index >= 0 && row[index] < 0) index--;
            result += (n - (index + 1));
        }
        return result;
    }
};