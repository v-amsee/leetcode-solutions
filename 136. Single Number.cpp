class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int n=nums.size(),snum=0;
        for (int i=0;i<n;i++)
        {
            snum=snum^nums[i];
        }
        
    return snum;}
};