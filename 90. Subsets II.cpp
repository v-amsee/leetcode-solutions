class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        thepowerset(nums,ans,0,subset);
    return ans;}

void thepowerset(vector<int>& nums,vector<vector<int>> &ans,int idx,vector<int> subset)
    {

        if(idx>=nums.size())
        {
            ans.push_back(subset);
            return;
        }
            subset.push_back(nums[idx]);
            thepowerset(nums,ans,idx +1,subset);
            subset.pop_back();
            while(idx+1 <nums.size() && nums[idx]==nums[idx+1])
                {
                    idx++;
                }
            thepowerset(nums,ans,idx +1,subset);
        
    }
};