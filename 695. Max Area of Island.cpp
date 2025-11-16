class Solution {
public:
    bool isSafe(int i,int j,int m,int n)
    {
        return i>=0 && i<m && j>=0 && j<n;
    }
    int dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        int maxarea=1;
        grid[i][j]=0;
        vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        for(int k=0;k<4;k++)
        {
            int newi = i + dirs[k][0];
            int newj = j + dirs[k][1];
            if(isSafe(newi,newj,m,n) && grid[newi][newj]==1)
               maxarea+=dfs(grid,newi,newj,m,n);
        }
    return maxarea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea{};
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {
                    maxarea=max(dfs(grid,i,j,m,n),maxarea);
                }
            }
        }
    return maxarea;
    }
};