//Optimal
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
   unordered_set<int> s(nums.begin(),nums.end());
   int ans=0;
   for (int num:s)
   {
    if(s.find(num-1)==s.end())
    {
        int len=1;
        while(s.find(num+len)!=s.end())
        {
            len++;
        }
    ans=max(ans,len);
    }
    
   }
   return ans; }
};

//Sorting Solution

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n=nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        int curr=nums[0],count=0,i=0;
        while(i<n)
        {
            if (curr!=nums[i])
            {
                curr=nums[i];
                count=0;
            }
            while(i <n&&nums[i]==curr)
            {
                i++;
            }

                count++;
                curr++;
                ans=max(ans,count);
        }
        return ans;
    }
};











//Brute Force Solution

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),ans=0;
        unordered_set<int> s(nums.begin(),nums.end());
        for (int i=0;i<n;i++)
        {
            int count=0,temp=nums[i];
            while (s.find(temp)!=s.end())
            {
                count++;
                temp++;
            }
            ans=max(ans,count);
        }
        
        
   return ans; }
};