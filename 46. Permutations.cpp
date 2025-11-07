//BackTracking

class Solution {
public:
vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        vector<bool> pick(nums.size(),false);
        dfs(nums,perm,pick);
        
    return ans;
    }
    void dfs(vector<int> &nums,vector<int> perm,vector<bool> &pick)
    {
        if( perm.size()==nums.size())
        {
            ans.push_back(perm);
            return;
        }

        for(int i=0;i< nums.size();i++)
        {if(!pick[i])
        {
            perm.push_back(nums[i]);
            pick[i]=true;
            dfs(nums,perm,pick);
            perm.pop_back();
            pick[i]=false;
        }
        }
    }
};

//Recursion

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {{}};
        }

        vector<int> tmp = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permute(tmp);
        vector<vector<int>> res;
        for (const auto& p : perms) {
            for (int i = 0; i <= p.size(); i++) {
                vector<int> p_copy = p;
                p_copy.insert(p_copy.begin() + i, nums[0]);
                res.push_back(p_copy);
            }
        }
        return res;
    }
};