class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l=i+1,r=n-1;
            while(l<r)
            {
                int _3sum = nums[l]+nums[r]+nums[i];
                if(_3sum <0)l++;
                else if (_3sum >0) r--;
                else
                {
                ans.push_back({nums[i],nums[l],nums[r]});
                l++;
                r--;
                while(l<r && nums[l]==nums[l-1]) l++;
                }
            }
        }
        return ans;
    }
};