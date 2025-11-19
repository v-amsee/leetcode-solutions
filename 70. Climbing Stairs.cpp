// Recursion
class Solution {
public:
    int helper(int n,int ind){
      if(ind==n)
        return 1;
      if(ind>n)
        return 0;

        return helper(n,ind+1) +helper(n,ind+2);
          }
    int climbStairs(int n) {
        return helper(n,0);
    }
};


//Memoization

class Solution {
public:
    int helper(int n,int ind,vector<int> &dp){
      if(ind==n)
        return 1;
      if(ind>n)
        return 0;
      if(dp[ind]!=-1)
        return dp[ind];

        return dp[ind]=helper(n,ind+1,dp) +helper(n,ind+2,dp);
          }
    int climbStairs(int n) {
       vector<int> dp(n+1,-1);
        return helper(n,0,dp);
    }
};

//Tabulation

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
        
    }
};

// Space Optimized

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int first = 1;
        int second = 2;
        int third;
        for (int i = 3; i <= n; i++) {
            third = first + second;
            first=second;
            second=third;
        }
        return second;
        
    }
};