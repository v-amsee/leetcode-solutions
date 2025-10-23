class Solution {
public:
    bool isAnagram(string s, string t) {
        int s1=s.size(); 
        int t1=t.size();
        unordered_map<char,int> mps,mpt;
        if (s1!=t1) return false;
        for(int i=0;i<t1;i++)
        {
            mps[s[i]]++;
            mpt[t[i]]++;
        }
        if (mps == mpt) return true;
        else return false;
        
    }
};