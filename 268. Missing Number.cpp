class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum,m,n=nums.size();
        sum=reduce(nums.begin(),nums.end());
        m=n*(n+1)/2 - sum;
    return m;
    }
};