class Solution {
public:
    int rob(const vector<int>& nums) {
        int prev = 0;
        int curr = 0;
        for (int money : nums) {
            int next = max(prev + money, curr);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
