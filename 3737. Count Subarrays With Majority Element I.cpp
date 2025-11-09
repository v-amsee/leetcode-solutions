class Solution {
public:
    
    int countMajoritySubarrays(vector<int>& nums, int target) {
        
        int ans{};
        for(int i=0;i<nums.size();i++)
            {vector<int> subarray;
             int count{};
                for(int j=i;j<nums.size();j++)
                {
                subarray.push_back(nums[j]);
                if(nums[j]==target) count++;
                if(count > (subarray.size()/2)) ans++;        
                }
            }
    return ans;
    }
};  