class Solution {
public:
    int minEatingSpeed(const vector<int>& piles, int h) {
        int slowest = 1;
        int fastest = *max_element(piles.begin(), piles.end());

        while (slowest < fastest) {
            int speed = slowest + (fastest - slowest) / 2;
            long long hours = 0;
            for (int pile : piles) hours += (pile + speed - 1) / speed;

            if (hours > h) slowest = speed + 1;
            else fastest = speed;
        }
        return slowest;
    }
};
