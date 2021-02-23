//
// Created by panrenhua on 2/23/21.
//

#ifndef LEETCODE_LEETCODE_400_H
#define LEETCODE_LEETCODE_400_H

#include "allheaders.h"
/** 400. 第 N 位数字
 * */
class Solution {
public:
    int findNthDigit(int n) {
        int index = 1;
        int count = 1;
        long num = 9 * count * index;
        while (n > num) {
            n -= num;
            count *= 10;
            index++;
            num = (long)9 * count * index;
        }

        string s = to_string(count + (n - 1) / index);

        return s[(n - 1) % index] - '0';
    }
};
#endif //LEETCODE_LEETCODE_400_H
