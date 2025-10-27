class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26,0),v2(26,0);
        if(v1.size()>v2.size())
            return false;
        for (const auto &s:s1)
        {
            v1[s-'a']++;        
        }
       int n=s1.size();
        for(int i=0;i<s2.size();i++)
        {
            v2[s2[i]-'a']++;
            if(i>=n) v2[s2[i-n]-'a']--;
            if(v1==v2) return true;
        }
    return false;
    }
};