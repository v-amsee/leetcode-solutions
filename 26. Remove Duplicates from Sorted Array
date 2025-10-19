class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniq=0;
        for (int i=1;i<nums.size();i++)
        {
            if (nums[i-1] != nums[i]) nums[++uniq]=nums[i];
        }
        return uniq+1;

    }
};