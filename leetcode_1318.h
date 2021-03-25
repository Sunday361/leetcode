//
// Created by panrenhua on 3/25/21.
//

#ifndef LEETCODE_LEETCODE_1318_H
#define LEETCODE_LEETCODE_1318_H
#include "allheaders.h"
/** 1318. 或运算的最小翻转次数
 * */
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int bita, bitb, bitc;
        int count = 0;
        while (a || b || c) {
            bita = a % 2;
            bitb = b % 2;
            bitc = c % 2;

            a >>= 1;
            b >>= 1;
            c >>= 1;

            if (bitc == 1) {
                if (bita == 0 && bitb == 0) {
                    count += 1;
                }
            }else {
                if (bita == 1) {
                    count += 1;
                }
                if (bitb == 1) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
#endif //LEETCODE_LEETCODE_1318_H
