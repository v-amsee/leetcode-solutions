
//Solution 1
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        map<multiset<char>,vector<string>> strmap;
        for (int i=0;i<strs.size();i++)
        {
            multiset<char> key(strs[i].begin(),strs[i].end());
            strmap[key].push_back(strs[i]);
        }

        for (auto it:strmap)
        {
            ans.push_back(it.second);
        }
    return ans;}
};

//Solution 2

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
    vector<vector<string>> ans;
    unordered_map<string,vector<string>> strmap;
    
    for (const auto &s :strs)
    { 
        vector<int> count(26,0);
        for (char c:s){
        count[c -'a']++;
        }
        string key=to_string(count[0]);
        for (int i=0;i<26;i++)
        {
            key+= ','+ to_string(count[i]);
        }
       strmap[key].push_back(s);

    }

    for (const auto &it :strmap )
    {
        ans.push_back(it.second);
    }
return ans;
    }
};