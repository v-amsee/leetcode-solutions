class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size(),count=1,majnum =nums[0];
        for (int i=1;i<n;i++)
        {
            if (count == 0) majnum=nums[i];
            if (nums[i]!= majnum) count--;
            else count++;
        }
        return majnum;
    }
};