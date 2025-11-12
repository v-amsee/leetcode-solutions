class Solution {
public:
    bool isSafe(int i,int j,int m,int n)
    {
        return (i>=0 && i< m && j>=0 && j< n);
    }
    void dfs(vector<vector<int>>& image,int i,int j,int m,int n,int org_color,int color)
    {
        image[i][j]=color;
        vector<vector<int>> dirs{{-1,0},{1,0},{0,-1},{0,1}};
        for(int k=0;k<4;k++)
        {
            int newi= i + dirs[k][0];
            int newj= j + dirs[k][1];
            if(isSafe(newi,newj,m,n) && image[newi][newj]==org_color)
            {
                dfs(image,newi,newj,m,n,org_color,color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int org_color =image[sr][sc];
        int m=image.size();
        int n=image[0].size();
        if(org_color==color) return image;
        dfs(image,sr,sc,m,n,org_color,color);

    return image;    
    }
};