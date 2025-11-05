class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    
        int sum=0;
        vector<int> candidate;
        dfs(candidates,candidate,sum,target,0);
       return ans; 
    }
    void dfs(vector<int>& candidates,vector<int>candidate,int sum, int target,int idx)
    {
        if(sum==target)
        {
            ans.push_back(candidate);
            return;
        }
        if (sum>target) return;
        if(idx>=candidates.size())
            return;
        candidate.push_back(candidates[idx]);
        sum+=candidates[idx];
        dfs(candidates,candidate,sum,target,idx);
        sum-=candidates[idx];
        candidate.pop_back();
        dfs(candidates,candidate,sum,target,idx+1);
    }

    
};