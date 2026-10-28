class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            string odd_palindrome = expand(i, i, s);
            if (odd_palindrome.size() > ans.size()) ans = odd_palindrome;
            string even_palindrome = expand(i, i + 1, s);
            if (even_palindrome.size() > ans.size()) ans = even_palindrome;
        }

        return ans;
    }

    string expand(int i, int j, string s) {
        int left = i;
        int right = j;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }

        return s.substr(left + 1, right - left - 1);
    }
};
