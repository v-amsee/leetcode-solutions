// DFS Solution

class Solution {
public:
    void dfs( int curr,map<int,vector<int>> &graph,set<int> &vis)
    {
        
        for(auto neighbor: graph[curr])
        {
            if(!vis.count(neighbor))
            {
                vis.insert(curr);
                dfs(neighbor,graph,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int ROWS =grid.size();
        int COLS =grid[0].size();
        map<int,vector<int>> graph;
        int cnt{};
        for(int r=0;r<ROWS;r++)
        {
        for(int c=0;c<COLS;c++)
        {
            if(grid[r][c]=='1')
            {
                int node = r*ROWS +c;
                graph[node].push_back(node);
                if(r-1 >-1 && grid[r-1][c]=='1') graph[node].push_back((r-1)*ROWS +c);
                if(r+1 <ROWS && grid[r+1][c]=='1') graph[node].push_back((r+1)*ROWS +c);
                if(c-1 >-1 && grid[r][c-1]=='1') graph[node].push_back(r*ROWS+c-1);
                if(c+1 < COLS && grid[r][c+1]=='1') graph[node].push_back(r*ROWS+c+1);
            }
        }
        }
        set<int> vis;
        for(auto node:graph)
        {
            if(!vis.count(node.first))
            {
                cnt++;
                dfs(node.first,graph,vis);
            }

        }
        return cnt;
    }
};

//BFS Solution
class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        
        int ROWS =grid.size();
        int COLS =grid[0].size();
        map<int,vector<int>> graph;
        int cnt{};
        for(int r=0;r<ROWS;r++)
        {
        for(int c=0;c<COLS;c++)
        {
            if(grid[r][c]=='1')
            {
                int node = r*ROWS +c;
                graph[node].push_back(node);
                if(r-1 >-1 && grid[r-1][c]=='1') graph[node].push_back((r-1)*ROWS +c);
                if(r+1 <ROWS && grid[r+1][c]=='1') graph[node].push_back((r+1)*ROWS +c);
                if(c-1 >-1 && grid[r][c-1]=='1') graph[node].push_back(r*ROWS+c-1);
                if(c+1 < COLS && grid[r][c+1]=='1') graph[node].push_back(r*ROWS+c+1);
            }
        }
        }
        set<int> vis;
        for(auto node:graph)
        {
            if(!vis.count(node.first))
            {
                cnt++;
                queue<int> bfs;
                bfs.push(node.first);
                while(!bfs.empty())
                {
                    int curr=bfs.front();
                    bfs.pop();
                    for(auto neighbor: graph[curr])
                    {
                        if(!vis.count(neighbor))
                        {
                            vis.insert(neighbor);
                            bfs.push(neighbor);
                        }
                    }
                }
            }

        }
        return cnt;
    }
};

//Clean DFS Solution
class Solution {
public:
    bool isSafe(int i, int j, int n, int m) {
        return (i>=0 && i<n && j>=0 && j<m);
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j, int n, int m) {
        vis[i][j] = true;
        vector<vector<int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        for(int k = 0; k<4; k++) {
            int newi = i + dir[k][0];
            int newj = j + dir[k][1];
            if(isSafe(newi, newj, n, m) && grid[newi][newj] == '1' && !vis[newi][newj]) 
                dfs(grid, vis, newi, newj, n, m);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(grid, vis, i, j, n, m);
                    res++;
                }
            }
        }
        return res;
    }
};