class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses_available_after_taking(numCourses);
        vector<int> num_courses_needed_to_take(numCourses, 0);
        for (const auto& p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            courses_available_after_taking[prereq].push_back(course);
            ++num_courses_needed_to_take[course];
        }

        queue<int> courses_available;
        for (int course = 0; course < numCourses; ++course) {
            if (num_courses_needed_to_take[course] == 0) courses_available.push(course);
        }

        int taken = 0;
        while (!courses_available.empty()) {
            int course_taken = courses_available.front();
            courses_available.pop();
            for (int potentially_available_course : courses_available_after_taking[course_taken]) {
                if (--num_courses_needed_to_take[potentially_available_course] == 0) {
                    courses_available.push(potentially_available_course);
                }
            }
            ++taken;
        }

        return taken == numCourses;
    }
};
