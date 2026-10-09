class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() : largest(1) {}

    int popSmallest() {
        if (!added.empty()) {
            int smallest_added = *added.begin();
            if (smallest_added < largest) {
                added.erase(added.begin());
                return smallest_added;
            }
        }
        return largest++;
    }

    void addBack(int num) { if (num < largest) added.insert(num); }

private:
    int largest;
    std::set<int> added;
};
