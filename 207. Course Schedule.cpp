class Solution {
public:
    bool dfs(vector<vector<int>> &graph,vector<bool> &visited, vector<bool> &visiting,int node)
    {
        visiting[node]=true;
        for(auto neighbor: graph[node])
        {
            if(visiting[neighbor])
                return false;
            if(!visited[neighbor])
            {
               if(!dfs(graph,visited,visiting,neighbor))
                    return false;
            }

        }
        visited[node]=true;
        visiting[node]=false;
    return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto prequisite: prerequisites)
            graph[prequisite[0]].push_back(prequisite[1]);
        vector<bool> visited(numCourses,false);
        vector<bool> visiting(numCourses,false);

        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(!dfs(graph,visited,visiting,i))
                    return false;
            }
        }
        return true;
    }
};