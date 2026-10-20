class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        std::array<int, 256> last;
        last.fill(-1);
        int left = 0, max_len = 0;
        const int n = static_cast<int>(s.size());
        for (int right = 0; right < n; ++right) {
            unsigned char c = static_cast<unsigned char>(s[right]);
            if (last[c] >= left) {
                left = last[c] + 1;
            }
            last[c] = right;
            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};
