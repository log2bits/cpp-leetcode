class Solution {
public:
    int majorityElement(const vector<int>& nums) {
        unordered_map<int, int> counts;
        counts.reserve(nums.size());
        const int threshold = static_cast<int>(nums.size()) / 2;

        for (int num : nums) {
            if (++counts[num] > threshold) return num;
        }
        return 0;
    }
};
