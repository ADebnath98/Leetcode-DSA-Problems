class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans; // Initialize a vector to store lucky numbers.
        vector<int> row(matrix.size(), 0); // Initialize a vector to store minimum values in each row.
        vector<int> col(matrix[0].size(), 0); // Initialize a vector to store maximum values in each column.
        
        // Find minimum values in each row.
        for (int i = 0; i < matrix.size(); i++) 
        {
            int n = matrix[i][0];
            for (int j = 0; j < matrix[0].size(); j++) 
            {
                n = min(n, matrix[i][j]); // Update 'n' with the minimum value in the row.
            }
            row[i] = n; // Store the minimum value in the 'row' vector.
        }
        
        // Find maximum values in each column.
        for (int j = 0; j < matrix[0].size(); j++) 
        {
            int n = matrix[0][j];
            for (int i = 0; i < matrix.size(); i++) 
            {
                n = max(n, matrix[i][j]); // Update 'n' with the maximum value in the column.
            }
            col[j] = n; // Store the maximum value in the 'col' vector.
        }
        
        // Compare minimum values in rows with maximum values in columns.
        for (int i = 0; i < matrix.size(); i++) 
        {
            for (int j = 0; j < matrix[0].size(); j++) 
            {
                if (row[i] == col[j]) 
                {
                    ans.push_back(row[i]); // If equal, it's a lucky number, so add it to 'ans'.
                }
            }
        }
        
        return ans; // Return the vector containing lucky numbers.
    }
};