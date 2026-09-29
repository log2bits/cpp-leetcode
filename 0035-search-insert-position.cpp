class Solution {
public:
    int searchInsert(const vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] < target) left = middle + 1;
            else right = middle - 1;
        }
        return left;
    }
};
