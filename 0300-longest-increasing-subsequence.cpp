class Solution {
public:
    int lengthOfLIS(const vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        vector<int> lis(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) lis[i] = max(lis[i], lis[j] + 1);
            }
        }

        return *max_element(lis.begin(), lis.end());
    }
};
