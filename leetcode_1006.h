//
// Created by panrenhua on 4/1/21.
//

#ifndef LEETCODE_LEETCODE_1006_H
#define LEETCODE_LEETCODE_1006_H
#include "allheaders.h"
/** 1006. 笨阶乘
 * */
class Solution {
public:
    int clumsy(int N) {
        if(N <= 2) return N;
        if(N == 3) return 6;
        int sum = N * (N - 1) / (N - 2) + N - 3;
        N -= 4;
        while (N >= 4) {
            sum += (-N * (N - 1) / (N - 2) + N - 3);
            N -= 4;
        }
        return sum - clumsy(N);
    }
};
#endif //LEETCODE_LEETCODE_1006_H
