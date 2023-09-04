class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>v(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0||i==n-1||j==m-1)
                {
                    if(v[i][j]==0&&board[i][j]=='O'){
                    q.push({i,j});
                    v[i][j]=1;}
                }
            }
            
        }
        int dr[]={-1,0,+1,0};
        int dc[]={0,+1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
              int  row=dr[i]+r;
                int col=dc[i]+c;
                if(row>=0&&row<n&&col>=0&&col<m&&board[row][col]=='O'&&v[row][col]==0)
                {
                    q.push({row,col});
                    v[row][col]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O'&&v[i][j]==0)
                {
                    board[i][j]='X';
                }
            }
        }
        //return board;
    }
};   