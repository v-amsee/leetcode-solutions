class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);

        int pre=1;
        for (int i=0;i<n;i++)
        {
            ans[i]=pre;
            pre*=nums[i];
        }

        int post=1;
        for (int j=n-1;j>-1;j--)
        {
            ans[j]*=post;
            post*=nums[j];
        }
    
     return ans;   
    }
};