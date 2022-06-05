class Solution {
public:
     bool isSafe1(vector<string>board, int col, int row){
    for(int i=0; i<row; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
     for(int i=row-1, j=col+1; i>=0 && j<board[0].size(); i--, j++){
        if(board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}
    
void printNQueens(vector<string>board,vector<vector<string>>&s , int row) {
    if(board.size() == 0)
        return;
    if(row == board.size()){
        s.push_back(board);
        return;
  }
    
  for(int i=0; i<board[0].size(); i++){
      if(isSafe1(board,i,row)){
          board[row][i] = 'Q';
          printNQueens(board,s ,row+1);
          board[row][i]= '.';
      }
  }
}
    int totalNQueens(int n) {
        string st = "";
        vector<vector<string>>v ;
        for(int i=0; i<n; i++){
            st += '.';
        }
        vector<string>s(n,st);
    
        printNQueens(s,v ,0);
        return v.size();
        
    }
};