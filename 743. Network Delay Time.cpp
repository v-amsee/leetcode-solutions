// Bellman Ford Algorithm

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        for(int i=1;i<n;i++)
        {
        for(auto edge:times)
        {
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            if(dist[u]!=INT_MAX && dist[u]+wt < dist[v])
                dist[v]= dist[u] + wt;
            
        }
        }
        int ans=-1;
        for(int i=1;i<=n;i++)
            ans=max(ans,dist[i]);

        return ans==INT_MAX?-1:ans;
    }
};

//Dijkstra's Algorithm

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> graph(n+1,vector<pair<int,int>>());

        for(auto time : times){
            graph[time[0]].push_back({time[1],time[2]});
        }

        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;

        priority_queue<pair<int,int>> pq;
        pq.push({0,k});

        while(!pq.empty())
        {
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            for(auto neighbor : graph[node])
            {
                int adjnode = neighbor.first;
                int wt =neighbor.second;
                if(dist[adjnode] > distance +wt)
                {
                    dist[adjnode]= distance + wt;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int ans=-1;
        for (int i=1;i<=n;i++)
        {
            ans=max(ans,dist[i]);
        }
        
        return ans==INT_MAX? -1:ans;
    }
};

//Floyd Warshall Algorithm

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
     vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    
    for(int i=0;i<n;i++)
        dist[i][i]=0;

    for(auto edge:times)
        dist[edge[0]-1][edge[1]-1] = edge[2];

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX)
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    int ans{INT_MIN};
    for(int i=0;i<n;i++)
    {
        if(dist[k-1][i]==INT_MAX)
            return -1;
        ans=max(dist[k-1][i],ans);
    }
    return ans;
    }
};