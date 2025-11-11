//DFS Solution

class Solution {
public:
    void dfs(int num,int n,int k,vector<int> &ans)
    {
        if(n==0)
        {
            ans.push_back(num);
            return;
        }
        int lastdigit=num%10;
        if(lastdigit + k <=9) dfs(num*10 + lastdigit + k,n-1,k,ans);
        if(k!=0 && lastdigit - k >=0) dfs(num*10 + lastdigit - k,n-1,k,ans);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for(int i=1;i<10;i++)
        {
            dfs(i,n-1,k,ans);
        }

        return ans;
    }
};

//BFS Solution
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        queue<int> bfs;
        for(int i=1;i<10;i++)
        {
            bfs.push(i);
        }
        int len=1;
        while(!bfs.empty() && len <n)
        {
            len++;
            int s=bfs.size();
            for(int i=0;i<s;i++)
            {
            int num=bfs.front();
            bfs.pop();
            int lastdigit=num%10;
            if(lastdigit + k <=9) bfs.push(num*10 + lastdigit + k);
            if(lastdigit - k >=0 && k!=0 ) bfs.push(num*10 + lastdigit - k);
            }
        }
        while(!bfs.empty())
        {
            ans.push_back(bfs.front());
            bfs.pop();
        }
        return ans;
    }
};