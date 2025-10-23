class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx=n-2;

        while(idx >=0 && nums[idx] >= nums[idx+1]) idx--;
        
        if (idx>=0) {
        int idx2 =n-1;
        while(nums[idx2]<=nums[idx]) idx2--;

        swap (nums[idx],nums[idx2]);
        }
        reverse(nums.begin()+idx +1,nums.end());

    }
};