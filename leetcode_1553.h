//
// Created by panrenhua on 3/22/21.
//

#ifndef LEETCODE_LEETCODE_1553_H
#define LEETCODE_LEETCODE_1553_H
#include "allheaders.h"
class Solution {
private:
    unordered_map<int, int> memo;

public:
    int minDays(int n) {
        if (n <= 1) {
            return n;
        }
        if (memo.count(n)) {
            return memo[n];
        }
        return memo[n] = min(n % 2 + 1 + minDays(n / 2), n % 3 + 1 + minDays(n / 3));
    }
};
#endif //LEETCODE_LEETCODE_1553_H
