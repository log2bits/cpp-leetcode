class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        std::vector<string> rows(numRows, "");

        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int rowNum = i % (numRows * 2 - 2);
            if (rowNum >= numRows - 1) {
                rowNum = (numRows - 1) - (rowNum - (numRows - 1));
            }
            rows[rowNum] += s[i];
        }

        string res = "";
        for (string row : rows) {
            res += row;
        }
        return res;
    }
};
