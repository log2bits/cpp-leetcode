class Solution {
public:
    int coinChange(const vector<int>& coins, int amount) {
        vector<int> best(amount + 1, INT_MAX);
        best[0] = 0;

        for (int x = 1; x <= amount; ++x) {
            for (int coin : coins) {
                if (coin <= x && best[x - coin] != INT_MAX) {
                    best[x] = min(best[x], best[x - coin] + 1);
                }
            }
        }

        return best[amount] == INT_MAX ? -1 : best[amount];
    }
};
