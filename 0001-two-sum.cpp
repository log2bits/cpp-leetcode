class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> complements;
        complements.reserve(nums.size());

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            auto it = complements.find(nums[i]);
            if (it != complements.end()) return {i, it->second};
            complements[target - nums[i]] = i;
        }
        return {};
    }
};
