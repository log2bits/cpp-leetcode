class Solution {
public:
    int lengthOfLastWord(const string& s) {
        int p = static_cast<int>(s.size());
        int len = 0;
        while (p > 0) {
            --p;
            if (s[p] != ' ') ++len;
            else if (len > 0) return len;
        }
        return len;
    }
};
