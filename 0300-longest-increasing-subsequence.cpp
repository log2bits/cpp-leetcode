class Solution {
public:
    int lengthOfLIS(const vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        vector<int> best(n, 1);

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] < nums[j]) best[i] = max(best[i], best[j] + 1);
            }
        }

        return *max_element(best.begin(), best.end());
    }
};
