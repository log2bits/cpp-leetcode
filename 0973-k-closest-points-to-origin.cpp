class Solution {
public:
    vector<vector<int>> kClosest(const vector<vector<int>>& points, int k) {
        // max-heap of (squared distance, index): distance computed once per
        // point, and the largest sits on top so it is the one evicted
        priority_queue<pair<int, int>> pq;

        int n = points.size();
        for (int i = 0; i < n; i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({dist, i});
            if (static_cast<int>(pq.size()) > k) pq.pop();
        }

        vector<vector<int>> result;
        result.reserve(pq.size());
        while (!pq.empty()) {
            result.push_back(points[pq.top().second]);
            pq.pop();
        }
        return result;
    }
};
