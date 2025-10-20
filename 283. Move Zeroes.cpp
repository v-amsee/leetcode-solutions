class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int nonzero=0,n=nums.size();

        for (int zero =0;zero<n;zero++)
        {
            if (nums[zero]!=0) swap(nums[nonzero++],nums[zero]);
        }  
        
    }
};