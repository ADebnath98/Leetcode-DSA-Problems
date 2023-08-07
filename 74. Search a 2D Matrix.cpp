class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m - 1;
        int row = 0;
        
        while (top <= bottom)
        {
            int mid = (top + bottom) >> 1;

            if (matrix[mid][0] > target)
                bottom = mid - 1;
            else
            {
                row = mid;
                top = mid + 1;
            }
        }
        
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;

            if (matrix[row][mid] == target)
                return true;
            
            else if (matrix[row][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};