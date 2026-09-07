class Solution {
public:
    int findKthLargest(const vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            if (static_cast<int>(minHeap.size()) > k) minHeap.pop();
        }
        return minHeap.top();
    }
};
