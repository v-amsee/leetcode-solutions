// Classic Recursion
class Solution {
public:
    int fib(int n) {
        if(n<=1) return 1;
    return fib(n-1) + fib(n-2);
    }
};

// Top Down Memoization Solution

class Solution {
public:
    int helper(int ind, vector<int> &dp){
    if(ind<=1) return ind;
    if(dp[ind]!= -1) return dp[ind];
    return dp[ind]=helper(ind-1,dp) + helper(ind-2,dp);}

    int fib(int n) {
        if(n<=1) return n;
        vector<int> dp(n+1,-1);
        helper(n,dp);
        return dp[n];
    }
};

//Bottom up Tabulation Solution

class Solution {
public:

    int fib(int n) {
        if(n==0) return 0;
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++)
            dp[i]=dp[i-1]+dp[i-2];
        return dp[n]; 
    }
};

//Space Optimized Solution

class Solution {
public:

    int fib(int n) {
        if(n<=1) return n;
        
        int seclast=0;
        int last=1;
        int ans;
        
        for(int i=2;i<=n;i++)
        {
            ans=seclast +last;
            seclast =last;
            last=ans;
        }
        return ans;
    }
};