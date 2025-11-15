class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());

        for(int i=0;i<n;i++)
        {
            vector<int> temp=points[i];
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            graph[i].push_back({abs(temp[0]-points[j][0])+abs(temp[1]-points[j][1]),j});
        }
        }
        int mincost=0;
        vector<int> vis(n,0);;
        pq.push({0,0});

        while(!pq.empty())
        {
            int node=pq.top().second;
            int cost=pq.top().first;
            pq.pop();
            if(vis[node])
                continue;
            vis[node]=1;
            mincost+=cost;
            
            for(auto neighbor :graph[node])
            {
                if(!vis[neighbor.second])
                    pq.push(neighbor);
            }

        }
        return mincost;
    }
};