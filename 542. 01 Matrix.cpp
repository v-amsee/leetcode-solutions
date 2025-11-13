class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(mat[i][j]==0)
                    q.push({i,j});
                else
                    mat[i][j]=m+n;
            }
        }
        vector<vector<int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            int i=curr.first,j=curr.second;
            q.pop();
            for(int k=0;k<4;++k)
            {
                int newi=i+dirs[k][0];
                int newj=j+dirs[k][1];
                if(newi <m && newi>=0 && newj < n && newj>=0)
                {
                    if(mat[newi][newj]>mat[i][j] +1)
                        {
                            mat[newi][newj] = mat[i][j]+1;
                            q.push({newi,newj});
                        }

                }
            }

        }
        return mat;
    }
};