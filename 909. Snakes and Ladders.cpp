class Solution {
    int n;
    int findColumn(int cellNumber){
        int row = (cellNumber-1)/n;
        int isEven = row%2 == 0;
        if(isEven){
            //when the row number is even
            return (cellNumber%n-1 + n)%n;
        }else{
            //when the row number is odd
            return (n - cellNumber%n)%n;
        };
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int lastCell = n*n;
        reverse(board.begin(), board.end());// So it would be easier for us to find row and col index by cell number

        queue<int> q;
        int cellNumber = 1;
        q.push(cellNumber);

        int row,col;
        int ans = 1;
        board[0][0] = 0; // make the current cell visited
        int numCells = 0; // number of cells in current layer of BFS.
        while(!q.empty()){
            cellNumber = q.front();
            q.pop();
            int count = 6; // to iterate through next 6 cells
            cellNumber++;
            while(count-- && cellNumber <= lastCell){
                row = (cellNumber-1)/n;
                col = findColumn(cellNumber);
                if(cellNumber == lastCell || board[row][col] == lastCell){
                    return ans;
                }
                if(board[row][col] > 0){ // if at current cell there is a ladder or snake
                    q.push(board[row][col]);
                }
                else if(board[row][col] < 0){ // if at current cell there is not any ladder or snake
                    q.push(cellNumber);
                }
                board[row][col] = 0; // make the current cell visited
                cellNumber++;
            }
            if(numCells == 0){ //if the current layer of bfs is traversed 
                numCells = q.size()-1; // set the number of cells in next layer
                ans++;
            }else{
                numCells--;
            }
        }
        return -1;
    }
};