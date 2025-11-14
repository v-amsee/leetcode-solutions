class Solution {
public:
    bool dfs(vector<vector<int>> &graph,vector<bool> &visited, vector<bool> &visiting,vector<int> &ans,int node)
    {
        visiting[node]=true;
        for(auto neighbor: graph[node])
        {
            if(visiting[neighbor])
                return false;
            if(!visited[neighbor])
            {
               if(!dfs(graph,visited,visiting,ans,neighbor))
                    return false;
            }

        }
        visited[node]=true;
        visiting[node]=false;
        ans.push_back(node);
    return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto prequisite: prerequisites)
            graph[prequisite[0]].push_back(prequisite[1]);
        vector<bool> visited(numCourses,false);
        vector<bool> visiting(numCourses,false);
        vector<int> ans;
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(!dfs(graph,visited,visiting,ans,i))
                    return {};
            }
        }
        return ans;
    }
        
};