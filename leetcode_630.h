//
// Created by panrenhua on 4/5/21.
//

#ifndef LEETCODE_LEETCODE_630_H
#define LEETCODE_LEETCODE_630_H
#include "allheaders.h"
/** 630. 课程表 III
 * 贪心,,,
 * */
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [&](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });

        priority_queue<int> pq;
        int day = 0;
        for (int i = 0; i < courses.size(); i++) {
            if (day + courses[i][0] <= courses[i][1]) {
                day += courses[i][0];
                pq.push(courses[i][0]);
            }else {
                pq.push(courses[i][0]);
                day += courses[i][0];

                int most = pq.top();
                pq.pop();
                day -= most;
            }
        }
        return pq.size();
    }
};
#endif //LEETCODE_LEETCODE_630_H
