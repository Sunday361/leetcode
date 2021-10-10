//
// Created by panrenhua on 2021/10/10.
//

#ifndef LEETCODE_LEETCODE_441_H
#define LEETCODE_LEETCODE_441_H
#include "allheaders.h"
/** 441. 排列硬币
 * */
class Solution {
public:
    int arrangeCoins(int n) {
        long long line = 1;
        while (line * (line + 1) / 2 <= n) {
            line++;
        }
        return line - 1;
    }
};
#endif //LEETCODE_LEETCODE_441_H
