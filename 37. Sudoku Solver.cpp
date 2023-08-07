class Solution {
public:
    #define N 9
    //Function to check if its possible to place the number 
    bool isPossible(char val,int row,int col,vector<vector<char>>& grid){
        for(int k=0;k<N;k++) {
            if(grid[k][col]==val) 
              return false;
        }
        for(int k=0;k<N;k++){
            if(grid[row][k]==val) 
              return false;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
            if(grid[3*(row/3)+i%3][3*(col/3)+j%3]==val) 
              return false;
            }
        }
        return true;
    }

    //Function to solve the sudoku
    bool solve(vector<vector<char>>& grid){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]=='.'){
                    //Check by placing numbers[1-9]
                    for(int val=1;val<=9;val++){
                        if(isPossible(val+'0',i,j,grid)){
                            grid[i][j]=val+'0';
                            //recursive call
                            if(solve(grid)){
                                return true;
                            }
                            //backtrack
                            grid[i][j]='.';
                        }
                    }
                    //Not possible to fill any number
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};