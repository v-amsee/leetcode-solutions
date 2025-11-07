class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,subset,target,0);
        return ans;
    }
    void dfs(vector<int>& candidates,vector<int> &subset,int target,int idx)
    {
        if(target==0)
        {  
            auto it =find(ans.begin(), ans.end(), subset);
            if(it==ans.end()){
            ans.push_back(subset);}
        }
        if(idx==candidates.size() ||target<0)
            return;

        subset.push_back(candidates[idx]);
        dfs(candidates,subset,target-candidates[idx],idx+1);
        subset.pop_back();
        while(idx+1<candidates.size()&&candidates[idx]==candidates[idx+1])
        {
            idx++;
        }
        dfs(candidates,subset,target,idx+1);

    }
};