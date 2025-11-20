// Recursion
class Solution {
public:
    int helper(vector<int>& nums,int ind,int n){
        if(ind>=n)
            return 0;
        int inc=nums[ind] + helper(nums,ind +2,n);
        int exc=helper(nums,ind+1,n);
        return max(inc,exc);
    }
    int rob(vector<int>& nums) {
       if(nums.size() == 1) return nums[0];
        return max( helper(nums, 0, nums.size()-1), helper(nums, 1, nums.size()));
    }
};

//Memoization

class Solution {
public:
    int helper(vector<int>& nums, int ind, int n, vector<int>& dp) {
        if (ind >= n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        int inc = nums[ind] + helper(nums, ind + 2, n, dp);
        int exc = helper(nums, ind + 1, n, dp);
        return dp[ind] = max(inc, exc);
    }

    int rob(vector<int>& nums) {
        int sz = nums.size();
        if (sz == 1) return nums[0];

        vector<int> dp1(sz, -1);
        int case1 = helper(nums, 0, sz - 1, dp1);

        vector<int> dp2(sz, -1);
        int case2 = helper(nums, 1, sz, dp2);

        return max(case1, case2);
    }
};
