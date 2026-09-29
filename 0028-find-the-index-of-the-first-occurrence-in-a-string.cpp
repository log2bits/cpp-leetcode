class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        int n = static_cast<int>(haystack.size());
        int m = static_cast<int>(needle.size());

        for (int i = 0; i + m <= n; ++i) {
            if (haystack.compare(i, m, needle) == 0) return i;
        }
        return -1;
    }
};
