//Solution 1

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n=nums.size();
        vector<int> ans;
        map<int,int> mp;
        for (int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int,int>> v;
        for( const auto &it :mp)
        {
            v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());

        for(int i=0;i<k;i++)
        {
            ans.push_back(v[i].second);
        }

        
    return ans;
    }
};


//Solution 2

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n=nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for (int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
       for (const auto &it : mp)
       {
        heap.push({it.second,it.first});
        if (heap.size()>k)
        {
            heap.pop();
        }
       }
       for (int i=0;i<k;i++)
       {
        ans.push_back(heap.top().second);
        heap.pop();
       }
    
    return ans;}
};

//Solution 3

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int n=nums.size();
        vector<vector<int>> cnt(nums.size()+1);
        unordered_map<int,int> mp;
        vector<int> ans;

        for (int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
      
      for(const auto &it:mp)
      {
        cnt[it.second].push_back(it.first);
      }


      for(int i=cnt.size()-1;i>0;--i)
      {
        for (int num:cnt[i])
        {
            ans.push_back(num);
            if (ans.size()==k)
            {
                return ans;
            }
        }
      }
    
    return ans;}
};