//
// Created by panrenhua on 2/13/21.
//

#ifndef LEETCODE_OFFER_14_II_H
#define LEETCODE_OFFER_14_II_H

#include "allheaders.h"
/** 剑指 Offer 14- II. 剪绳子 II
 * */
class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n-1;
        long rs = 1;
        while (n > 4) {
            rs *= 3;
            rs %= 1000000007;
            n -= 3;
        }
        return (rs * n) % 1000000007;
    }
};
#endif //LEETCODE_OFFER_14_II_H
