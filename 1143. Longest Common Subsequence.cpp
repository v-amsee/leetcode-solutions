// Recursion
class Solution {
public:
    int helper(string &text1,string &text2,int ind1,int ind2){
        if(ind1 >=text1.size() || ind2 >= text2.size())
            return 0;
        if(text1[ind1]==text2[ind2])
            return 1 + helper(text1,text2,ind1+1,ind2+1);
        
        return max(helper(text1,text2,ind1+1,ind2),helper(text1,text2,ind1,ind2+1));

    }
    int longestCommonSubsequence(string text1, string text2) {
        return helper(text1,text2,0,0);
    }
};

//Memoization

class Solution {
public:
    int helper(string &text1,string &text2,int ind1,int ind2,vector<vector<int>> &dp){
        if(ind1 >=text1.size() || ind2 >= text2.size())
            return 0;
        if(dp[ind1][ind2]!= -1)
            return dp[ind1][ind2];
        if(text1[ind1]==text2[ind2])
            return dp[ind1][ind2]=1 + helper(text1,text2,ind1+1,ind2+1,dp);
        
        return dp[ind1][ind2]= max(helper(text1,text2,ind1+1,ind2,dp),helper(text1,text2,ind1,ind2+1,dp));

    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(text1,text2,0,0,dp);
    }
};

//Tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1 + dp[i-1][j-1];
                }
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    return dp[m][n];
    }
};

//Space Optimization

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        for(int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1])
                {
                    curr[j]=1 + prev[j-1];
                }
                else
                    curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
    return curr[n];
    }
};