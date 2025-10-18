class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
     
        int  right=0,left=0;
        long  sum=0;
        int  maxfreq=0;
        long  target;
        sort(nums.begin(),nums.end());
        for (int right=0;right <nums.size();right++)
        {
            target =nums[right];
            sum+=target;
            while((right-left +1)*target - sum >k)
            {
                sum-=nums[left];
                left+=1;
            }
            maxfreq=max(maxfreq,right - left +1);
        
       }
        
     return maxfreq;}
};