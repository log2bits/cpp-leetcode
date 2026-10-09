class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto cmp = [](const auto& a, const auto& b) { return a[0] < b[0]; };
        std::sort(intervals.begin(), intervals.end(), cmp);

        vector<int> new_interval = intervals[0];
        vector<vector<int>> result;

        for (const auto& interval : intervals) {
            if (intersecting(interval, new_interval)) {
                new_interval = join(interval, new_interval);
            } else {
                result.push_back(new_interval);
                new_interval = interval;
            }
        }
        if (!new_interval.empty()) result.push_back(new_interval);
        return result;
    }

    bool intersecting(const vector<int>& a, const vector<int>& b) {
        return a[0] <= b[1] && b[0] <= a[1];
    }

    vector<int> join(const vector<int>& a, const vector<int>& b) {
        return vector<int>{std::min(a[0], b[0]), std::max(a[1], b[1])};
    }
};
