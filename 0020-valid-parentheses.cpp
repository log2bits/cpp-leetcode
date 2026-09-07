class Solution {
public:
    bool isValid(const string& s) {
        if (s.size() % 2 != 0) return false;

        static const unordered_map<char, char> closers = {
            {')', '('}, {']', '['}, {'}', '{'}
        };

        stack<char> st;
        for (char c : s) {
            auto it = closers.find(c);
            if (it == closers.end()) {
                st.push(c);
                continue;
            }
            if (st.empty() || st.top() != it->second) return false;
            st.pop();
        }
        return st.empty();
    }
};
