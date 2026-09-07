class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int lowest = INT_MAX;
        int best = 0;

        for (int price : prices) {
            if (price < lowest) lowest = price;
            else if (price - lowest > best) best = price - lowest;
        }
        return best;
    }
};
