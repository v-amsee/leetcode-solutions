class Solution {
    int rows;
    int cols;
    // set<pair<int,int>> path ;
public:
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();
        for (int r=0;r<rows;r++)
        {
            for(int c=0;c<cols;c++)
            {
                if( dfs(board,word,r,c,0))
                {
                    return true;
                }
            }
        }
    return false;
    }

    bool dfs(vector<vector<char>>& board, string &word,int r,int c,int idx)
    {
        if(idx==word.size())
        {
            return true;
        }
        if(r<0 || c<0 || r>=rows || c>=cols||board[r][c]!=word[idx]|| board[r][c] == '#')  
        {
            return false;
        }

        board[r][c] = '#';
        bool ans=dfs(board,word,r+1,c,idx +1)||dfs(board,word,r-1,c,idx +1)||dfs(board,word,r,c+1,idx +1)||dfs(board,word,r,c-1,idx +1);
        board[r][c]=word[idx];

    return ans;}
};