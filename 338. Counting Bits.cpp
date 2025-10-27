class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++)
        {
            int count=0;
            for(int j=0;j<32;j++)
            {
                if(1<<j &i) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};