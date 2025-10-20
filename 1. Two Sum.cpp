class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> mp;
        int n=nums.size();
        vector<int> ans;
        for (int i=0;i<n;i++) mp[target-nums[i]]=i;
        for (int j=0;j<n;j++)
        {   
            auto it=mp.find(nums[j]);
            if(it !=mp.end() && (*it).second!=j)
            {
                ans.insert(ans.begin(),{j,(*it).second});
                break;
        
            }
              }
    return ans; }
};