class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        const string& first = strs[0];
        size_t i = 0;

        while (i < first.size()) {
            for (const string& str : strs) {
                if (i >= str.size() || str[i] != first[i]) return first.substr(0, i);
            }
            ++i;
        }

        return first;
    }
};
