class Solution {

public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(s,part,0,0);

    return ans;
    }

    void dfs( string s,vector<string>part,int j,int i)
        {
        if(i>=s.size())
        {
            if(i==j)
            {
                ans.push_back(part);
            }
            return;
        }
        if(isPali(s,j,i))
        {
            part.push_back(s.substr(j,i-j+1));
            dfs(s,part,i+1,i+1);
            part.pop_back();
        }
        dfs(s,part,j,i+1);

        }
    bool isPali( string &s, int l, int r)
    {
        while(l<=r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};