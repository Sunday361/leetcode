//
// Created by panrenhua on 1/17/21.
//

#ifndef LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H
#define LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H

#include "allheaders.h"
/** leetcode-weekly-contest-229
 * */
class Solution {
public:
    // 5703. 最大平均通过率
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        vector<vector<double>> vs;
        auto cmp = [&](vector<double>& a, vector<double>& b)->bool {
            return a[2] < b[2];
        };
        priority_queue<vector<double>, vector<vector<double>>, decltype(cmp)> q{cmp};
        for (auto& c : classes) {
            vector<double> v(3);
            v[0] = c[0]; v[1] = c[1];
            v[2] = (c[0] + 1) * 1.0 / (c[1] + 1) - (c[0] * 1.0 / c[1]);
            q.emplace(v);
        }

        while (extraStudents > 0) {
            auto top = q.top();
            q.pop();

            while (top[2] > q.top()[2] && extraStudents > 0) {
                top[0]++;
                top[1]++;

                top[2] = (top[0] + 1) * 1.0 / (top[1] + 1) - (top[0] * 1.0 / top[1]);
            }
            q.emplace(top);
        }
        double ans = 0.0;
        while (!q.empty()) {
            ans += (q.top()[0] * 1.0 / q.top()[1]);
            q.pop();
        }
        return ans / classes.size();
    }
    // 5704. 好子数组的最大分数
    int maximumScore(vector<int>& nums, int k) {

    }
};

#endif //LEETCODE_LEETCODE_WEEKLY_CONTEST_224_H
