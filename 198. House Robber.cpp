//Recursion

class Solution {
public:

    int helper(vector<int>& nums, int ind, int n) {
        if(ind >= n) return 0;
        int inc = nums[ind] + helper(nums, ind+2, n);
        int exc = helper(nums, ind+1, n);
        return max(inc, exc);
    }

    int rob(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
};



//Memoization
class Solution {
public:

    int helper(vector<int>& nums, int ind, int n,vector<int> &dp) {
        if(ind >= n) return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int inc = nums[ind] + helper(nums, ind+2, n,dp);
        int exc = helper(nums, ind+1, n,dp);
        return dp[ind] = max(inc, exc);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return helper(nums, 0, n,dp);
    }
};
// Tabulation

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n, 0);

        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-2], nums[n-1]);

        for (int i = n-3; i >= 0; i--) {
            int take = nums[i] + dp[i+2];
            int skip = dp[i+1];
            dp[i] = max(take, skip);
        }

        return dp[0];
    }
};
//SO

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0, prev2 = 0;
        for (int x : nums) {
            int take = x + prev2;
            int skip = prev1;
            int curr = max(take, skip);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
