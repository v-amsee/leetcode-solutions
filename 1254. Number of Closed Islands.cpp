class Solution {
public:
    bool isSafe(int i, int j, int n, int m) {
        return (i>=0 && i<n && j>=0 && j<m);
    }

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j, int n, int m) {
        vis[i][j] = true;
        bool closed = !(i == 0 || i == n - 1 || j == 0 || j == m - 1);
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        for(int k = 0; k<4; k++) {
            int newi = i + dir[k][0];
            int newj = j + dir[k][1];
            if (!isSafe(newi, newj, n, m)) {
                closed = false;
                continue;
            }
            
            if(grid[newi][newj] == 0 && !vis[newi][newj]){
                if (!dfs(grid, vis, newi, newj, n, m))
                    closed = false;         
            }
        }
        return closed;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == 0) {
                   if( dfs(grid, vis, i, j, n, m)) res++;
                }
            }
        }
        return res;
    }
};