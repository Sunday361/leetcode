//
// Created by panrenhua on 4/5/21.
//

#ifndef LEETCODE_LEETCODE_210_H
#define LEETCODE_LEETCODE_210_H
#include "allheaders.h"
/** 210. 课程表 II
 * */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses + 1, vector<int>(numCourses + 1));
        vector<int> d(numCourses);
        for (auto& p : prerequisites) {
            for (int i = 1; i < p.size(); i++) {
                g[p[i]][p[0]] = 1;
                d[p[0]] += 1;
            }
        }

        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (d[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int f = q.front();
            q.pop();
            ans.push_back(f);
            for (int i = 0; i < g[f].size(); i++) {
                if (g[f][i] == 1) {
                    d[i] -= 1;
                    if (d[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }
        if (ans.size() == numCourses) return ans;
        return {};
    }
};
#endif //LEETCODE_LEETCODE_210_H
