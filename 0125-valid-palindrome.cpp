class Solution {
public:
    bool isPalindrome(const string& s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left < right) {
            if (!isalnum(static_cast<unsigned char>(s[left]))) {
                left++;
                continue;
            }
            if (!isalnum(static_cast<unsigned char>(s[right]))) {
                right--;
                continue;
            }
            if (tolower(static_cast<unsigned char>(s[left])) !=
                tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
