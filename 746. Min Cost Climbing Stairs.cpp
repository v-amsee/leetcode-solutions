//Recursion
class Solution {
public:
    int helper(vector<int>& cost,int ind){
        if(ind>=cost.size())
            return 0;
        return cost[ind] + min(helper(cost,ind+1),helper(cost,ind +2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(helper(cost,0),helper(cost,1));
    }
};

//Memoization

class Solution {
public:
    int helper(vector<int>& cost,int ind,vector<int> &dp){
        if(ind>=cost.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        return dp[ind] = cost[ind] + min(helper(cost,ind+1,dp),helper(cost,ind +2,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1); 
        return min(helper(cost,0,dp),helper(cost,1,dp));
    }
};

//Tabulation

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);

        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1],
                        dp[i - 2] + cost[i - 2]);
        }

        return dp[n];
    }
};

//Space Optimized

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for (int i = cost.size() - 3; i >= 0; i--) {
            cost[i] += min(cost[i + 1], cost[i + 2]);
        }
        return min(cost[0], cost[1]);
    }
};