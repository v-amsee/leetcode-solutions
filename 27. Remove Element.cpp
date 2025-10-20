class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int slowp=0,fastp=0;
        while(slowp<n && fastp<n)
        {
            if (nums[fastp]!=val)nums[slowp++]=nums[fastp++];
            else fastp++;

        }
    return slowp;}
};