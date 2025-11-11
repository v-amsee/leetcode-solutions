//DFS Adjacency List
class Solution {
public:
    bool dfs( int n,vector<vector<int>>&graph,vector<bool> &vis,int src,int dest)
    {
        if(src==dest)return true;
        vis[src]=true;
        for(int i=0;i<graph[src].size();i++)
        {
            int v=graph[src][i];
            if(!vis[v])
            {
                if(dfs(n,graph,vis,v,dest))
                    return true;
            }
        }

    return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
    vector<vector<int>> graph(n,vector<int>{});
    for(auto edge:edges)
    {
        int u{edge[0]};
        int v{edge[1]};
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> vis(n,false);

    return dfs(n,graph,vis,source,destination);
    }

};

//BFS Adjacency List
class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
    vector<vector<int>> graph(n,vector<int>{});
    for(auto edge:edges)
    {
        int u{edge[0]};
        int v{edge[1]};
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> vis(n,false);

    queue<int> bfs;
    bfs.push(source);
    vis[source]=true;
    while(!bfs.empty())
    {
        int fnt = bfs.front();
        bfs.pop();
         if(fnt ==destination) return true;
        
        for(auto neighbour : graph[fnt] )
        {
        if(!vis[neighbour])
        {
        bfs.push(neighbour);
        vis[neighbour]=true;
        }

        }
    }
    return false;
    }

};



//BFS Adjacency Matrix
class Solution {
public:

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<vector<bool>> graph(n,vector<bool>(n,false));
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            graph[u][v]=true;
            graph[v][u]=true;
        }
    queue<int> bfs;
    vector<bool> vis(n,false);
    bfs.push(source);
    vis[source]=true;
    while(!bfs.empty())
    {
        int fr{bfs.front()};
        bfs.pop();
        for(int i=0;i<n;i++)
        {
            if(graph[fr][i] && !vis[i])
            {
                if(i==destination) return true;
                vis[i]=true;
                bfs.push(i);
            }
        }

    }

    return false;
    }
};

//DFS Adjacency Matrix

class Solution {
public:
    bool dfs( int n,vector<vector<bool>> &graph,vector<bool> &vis,int src,int dest)
    {
        if(src==dest)
        {
            return true;
        }
        vis[src]=true;
        for(int i=0;i<n;i++)
        {
            if(graph[src][i] && !vis[i])
            {
                if(dfs(n,graph,vis,i,dest))
                    return true;
            }
        }
    return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<vector<bool>> graph(n,vector<bool>(n,false));
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            graph[u][v]=true;
            graph[v][u]=true;
        }
    vector<bool> vis(n,false);
   bool ans= dfs(n,graph,vis,source,destination);
    return ans;
    }
};