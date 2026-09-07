class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        unordered_map<string, vector<string>> buckets;
        buckets.reserve(strs.size());

        for (const string& str : strs) {
            array<int, 26> count{};
            for (char c : str) count[c - 'a']++;

            string key;
            key.reserve(64);
            for (int i = 0; i < 26; i++) {
                key += to_string(count[i]);
                key += '#';
            }

            buckets[key].push_back(str);
        }

        vector<vector<string>> result;
        result.reserve(buckets.size());
        for (auto& [key, group] : buckets) result.push_back(std::move(group));
        return result;
    }
};
