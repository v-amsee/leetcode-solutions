class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(),end=0,ans=nums[0];

        for (int i=0;i<n;i++)
        {
            end=max(nums[i]+end,nums[i]);
            ans=max(end,ans);
        }
        return ans;
    }
};