//
// Created by panrenhua on 5/1/21.
//

#ifndef LEETCODE_LEETCODE_690_H
#define LEETCODE_LEETCODE_690_H
#include "allheaders.h"
/** 690. 员工的重要性
 * */
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> e;

        for (auto& employee : employees) {
            e[employee->id] = employee;
        }

        queue<int> q;
        q.push(id);
        int ans = 0;
        while (!q.empty()) {
            int f = q.front(); q.pop();
            ans += e[f]->importance;
            for (auto& v : e[f]->subordinates) {
                q.push(v);
            }
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_690_H
