//Recursion
class Solution {
public:
    bool isPalindrome(string &s,int start, int end)
    {
        while(start<=end)
        {
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
    return true;
    }
    string longestPalindrome(string s) {
        string ans;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j))
                {   
                    if(j-i+1 > ans.size()){
                        ans=s.substr(i,j-i+1);
                    }
                }
            }
        }
    return ans;
    }
};

//Bottom up

class Solution {
public:

    string longestPalindrome(string s) {
        string ans=s.substr(0,1);
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(int l=1;l<=n;l++){
            for(int i=0;i<=n-l;i++){
                int j=i+l-1;
                if(i==j) dp[i][j]==true;
                else if(s[i]==s[j]&&(j==i+1 || dp[i+1][j-1])){
                    dp[i][j]=true;
                    ans=s.substr(i,l);
                }
            }
        }
    return ans;
    }
};