//
// Created by panrenhua on 1/23/21.
//

#ifndef LEETCODE_LEETCODE_338_H
#define LEETCODE_LEETCODE_338_H

#include "allheaders.h"
/** 338. 比特位计数
 * n & (n - 1) 可以去除最后一位 1  而且 n & (n - 1) 比 n 小
 * */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num + 1, 0);
        if (num == 0) return v;
        v[1] = 1;
        for (int i = 2; i < v.size(); i++) {
            v[i] = v[i & (i - 1)] + 1;
        }
        return v;
    }
};

#endif //LEETCODE_LEETCODE_338_H
