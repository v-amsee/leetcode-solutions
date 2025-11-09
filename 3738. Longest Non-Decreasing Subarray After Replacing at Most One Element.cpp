class Solution {
public:
   int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<int> L(n, 1), R(n, 1);
    for (int i = 1; i < n; ++i)
        if (nums[i] >= nums[i - 1]) L[i] = L[i - 1] + 1;
    for (int i = n - 2; i >= 0; --i)
        if (nums[i] <= nums[i + 1]) R[i] = R[i + 1] + 1;

    int ans = *max_element(L.begin(), L.end());
    for (int i = 0; i < n; ++i) {
        if (i == 0)
            ans = max(ans, 1 + R[1]);
        else if (i == n - 1)
            ans = max(ans, L[n - 2] + 1);
        else {
            int left = L[i - 1], right = R[i + 1];
            if (nums[i - 1] <= nums[i + 1])
                ans = max(ans, left + 1 + right);
            ans = max(ans, max(left + 1, right + 1));
        }
    }
    return ans;
}
};