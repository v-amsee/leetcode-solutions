class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,maxfreq=0,ans=0;
        unordered_map <int,int> count;
        for (int r=0;r<s.size();r++)
        {
            count[s[r]]++;
           int maxfreq = max( count[s[r]],maxfreq);
           while(r-l +1 - maxfreq > k)
           {
            count[s[l]]--;
            l++;
           }
           ans =max(ans,r-l + 1);

        }
    return ans;
    }
};