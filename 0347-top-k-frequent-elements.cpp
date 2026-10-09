class Solution {
public:
    std::vector<int> topKFrequent(const std::vector<int>& nums, const int k) {
        std::unordered_map<int, int> map;
        for (int num : nums) map[num]++;

        auto cmp = [](auto a, auto b) { return a.second > b.second; };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);

        for (const auto& p : map) {
            pq.push(p);
            if (static_cast<int>(pq.size()) > k) pq.pop();
        }

        std::vector<int> top_k{};
        while (!pq.empty()) { top_k.push_back(pq.top().first); pq.pop(); }
        return top_k;
    }
};
