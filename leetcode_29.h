//
// Created by panrenhua on 2021/10/12.
//

#ifndef LEETCODE_LEETCODE_29_H
#define LEETCODE_LEETCODE_29_H
#include "allheaders.h"
class Solution {
public:
    using ll = long long;
    int divide(int dividend, int divisor) {
        ll x = dividend, y = divisor;
        ll f = (x > 0 && y < 0) || (x < 0 && y > 0) ? -1 : 1;
        ll a = abs(x), b, count;
        ll res = 0;
        while (a > 0) {
            count = 1;
            b = abs(y);
            while (b <= a) {
                b = b << 1;
                count = count << 1;
            }
            b = b >> 1;
            count = count >> 1;
            a = a - b;
            res += count;
        }
        if (f == -1) {
            res = -res;
        }
        if (res > INT32_MAX) res = INT32_MAX;
        if (res < INT32_MIN) res = INT32_MIN;
        return res;
    }
};
#endif //LEETCODE_LEETCODE_29_H
