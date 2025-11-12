
//DFS Solution
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool> &vis,int curr,int n)
    {
        for( int i=0;i<n;i++)
        {
            if(isConnected[curr][i]==1 && !vis[i])
            {
                vis[i]=true;
                dfs(isConnected,vis,i,n);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,false);
        int cnt{};
        for (int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(isConnected,vis,i,n);
            }

        }
        return cnt;
    }
};

// BFS Solution

class Solution {
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n,false);
        int cnt{};

        for (int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                queue<int> bfs; 
                bfs.push(i);
                cnt++;
                vis[i]=true;
                while(!bfs.empty())
                {
                    int fr{bfs.front()};
                    bfs.pop();
                    for(int j=0;j<n;j++)
                    {
                    if(isConnected[fr][j] &&!vis[j])
                    {
                        vis[j]=true;
                        bfs.push(j);
                    }
                    }
                }
            }
            }
         return cnt;
        }
       
};