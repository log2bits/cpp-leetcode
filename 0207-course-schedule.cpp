class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> unlocks(numCourses);
        vector<int> prereqs_left(numCourses, 0);
        for (const auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            unlocks[prereq].push_back(course);
            ++prereqs_left[course];
        }

        queue<int> ready;
        for (int course = 0; course < numCourses; ++course) {
            if (prereqs_left[course] == 0) ready.push(course);
        }

        int taken = 0;
        while (!ready.empty()) {
            int course = ready.front();
            ready.pop();
            for (int unlocked : unlocks[course]) {
                if (--prereqs_left[unlocked] == 0) ready.push(unlocked);
            }
            ++taken;
        }

        return taken == numCourses;
    }
};
