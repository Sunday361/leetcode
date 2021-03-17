//
// Created by panrenhua on 3/17/21.
//

#ifndef LEETCODE_LEETCODE_1109_H
#define LEETCODE_LEETCODE_1109_H
#include "allheaders.h"
/** 1109. 航班预订统计
 * */
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        /**  b[i] = a[i] - a[i - 1];
             b[0] = a[0];
             对于 a[u] -> a[v] 上所有元素加上 k
             b[u] + k, b[v + 1] - k
        */
        for (int i = 0; i < bookings.size(); i++) {
            auto v = bookings[i];
            b[v[0] - 1] += v[2];
            if (v[1] < n)
                b[v[1]] -= v[2];
        }
        a[0] = b[0];
        for (int i = 1; i < n; i++) {
            a[i] = a[i - 1] + b[i];
        }
        return a;
    }
};
#endif //LEETCODE_LEETCODE_1109_H
