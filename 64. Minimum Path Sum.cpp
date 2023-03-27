Intuition
While traversing the grid we need to check for two cells, the adjacent upper cell and the adjacent left cell. Whichever has minimum path sum, we will update that sum on our current cell adding the value of current cell as well. At the end on the last cell we can find the minimum path sum for the given grid.

Approach
The updations can be made in the given grid itself. We dont need to create a seperate 2D dp array.
The steps are as follows -:

Use two variables n and m to store the size of rows and columns in the given loop.
Iterate using two for loops to reach each and every cell.
If the cell belongs to the uppermost row or leftmost column then update the cell using the adjacent left cell or the adjacent upper cell respectively.
Else update the current cell using min(grid[i-1][j], grid[i][j-1]). This step updated the value of current cell by choosing the minimum value out of the left cell and upper cell and adding value of current cell.
Atlast return the value of the last cell i.e. grid[n-1][m-1]
NOTE THAT value of grid[0][0] is kept intact, since that is the base case.

Complexity
Time complexity:
O(m*n) - Since we traverse and update each cell.

Space complexity:
O(1) - Since no extra space is used.



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i==0 and j!=0)
                    grid[i][j]+=grid[i][j-1];
                if(j==0 and i!=0)
                    grid[i][j]+=grid[i-1][j];
                if(i!=0 and j!=0)
                    grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
            }
        }
        
        return grid[n-1][m-1];
    }
};