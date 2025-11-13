class Solution {
public:
    bool isSafe(int i,int j,int m,int n)
    {
        return (i>=0 && i<m && j>=0 && j<n);
    }
    void dfs( vector<vector<char>> &board,int i,int j, int m,int n,char target,char newTile)
    {
        board[i][j]=newTile;
        vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;++k)
        {
            int newi = i + dirs[k][0];
            int newj = j + dirs[k][1];
            if(isSafe(newi,newj,m,n) && board[newi][newj]==target)
                dfs(board,newi,newj,m,n,target,newTile);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;++i)
        {

            if(board[i][0]=='O')
                dfs(board,i,0,m,n,'O','V');
            if(board[i][n-1]=='O')
                dfs(board,i,n-1,m,n,'O','V');
        }
        for(int i=0;i<n;++i)
        {
            if(board[0][i]=='O')
                dfs(board,0,i,m,n,'O','V');
            if(board[m-1][i]=='O')
                dfs(board,m-1,i,m,n,'O','V');
        }
        
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(board[j][k] == 'O')
                    dfs(board,j,k,m,n,'O','X');
            }
        }

    for(int i=0;i<m;++i)
        {
            if(board[i][0]=='V')
                dfs(board,i,0,m,n,'V','O');
            if(board[i][n-1]=='V')
                dfs(board,i,n-1,m,n,'V','O');
        }
        for(int i=0;i<n;++i)
        {
            if(board[0][i]=='V')
                dfs(board,0,i,m,n,'V','O');
            if(board[m-1][i]=='V')
                dfs(board,m-1,i,m,n,'V','O');
        }
        
        
    }
};