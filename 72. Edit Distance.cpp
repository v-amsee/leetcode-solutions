// Recursion

class Solution {
public:
    int helper(string s1, string s2, int ind1, int ind2){

        if(ind1>=s1.size())
            return s2.size() - ind2;

        if(ind2>=s2.size())
            return s1.size() - ind1;

        if(s1[ind1]==s2[ind2])
            return helper(s1,s2,ind1+1,ind2+1);
        
        return 1 + min({helper(s1,s2,ind1+1,ind2 + 1),helper(s1,s2,ind1+1,ind2),helper(s1,s2,ind1,ind2 +1)});
        

    }
    int minDistance(string word1, string word2) {

        return helper(word1,word2,0,0);
        
    }
};

//Memoization

class Solution {
public:
    int helper(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp){

        if(ind1>=s1.size())
            return s2.size() - ind2;
        if(ind2>=s2.size())
            return s1.size() - ind1;
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if(s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = helper(s1, s2, ind1+1, ind2+1, dp);
        return dp[ind1][ind2] = 1+min({helper(s1, s2, ind1, ind2+1, dp), 
                        helper(s1, s2, ind1+1, ind2, dp), helper(s1, s2, ind1+1, ind2+1, dp)});

    }
    int minDistance(string word1, string word2) {

        vector<vector<int>> dp(word1.size(), vector<int> (word2.size(), -1));
        return helper(word1,word2,0,0,dp);
        
    }
};

// Tabulation

class Solution {
public:

    int minDistance(string word1, string word2) {

        int m=word1.size();
        int n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i = 1; i<=m; i++)
            dp[i][0] = i;
        
        for(int j = 1; j<=n; j++)
            dp[0][j] = j;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
       return dp[m][n];
        
    }
};

//Space Optimized

class Solution {
public:

    int minDistance(string word1, string word2) {

        int m=word1.size();
        int n=word2.size();
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        
        for(int j = 1; j<=n; j++)
            prev[j] = j;

        for(int i=1;i<=m;i++){
           curr[0] = i;
            for(int j = 1; j<=n ; j++) {
                if(word1[i-1] == word2[j-1])
                    curr[j] = prev[j-1];
                else curr[j] = 1 + min({prev[j], curr[j-1], prev[j-1]});
            }
            prev = curr;
        }
       return prev[n];
        
    }
};