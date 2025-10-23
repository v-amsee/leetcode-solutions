class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int pos=0,neg=0,n=nums.size(),arrp=0;
        vector<int> arr;
        while(arrp<n)
        {
            while(pos < n && nums[pos] <0)pos++;
            arr.push_back(nums[pos++]);
            arrp++;
            while(neg<n && nums[neg]>0) neg++;
            arr.push_back(nums[neg++]);
            arrp++;
        }
        nums = arr;
    return nums;}
};