class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_ele{};
        int ans{};
        for (const auto &num:nums)
            {
                if(num>max_ele)
                {
                    max_ele=num;
                }
            }
        for(auto &num : nums)
            {
                ans+=max_ele-num;
            }
        return ans;
    }
};