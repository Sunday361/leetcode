//
// Created by panrenhua on 3/13/21.
//

#ifndef LEETCODE_LEETCODE_915_H
#define LEETCODE_LEETCODE_915_H
#include "allheaders.h"
/** 915. 分割数组
 * 扫描一遍
 * */
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int maxval = A[0], cur = 0;
        int maxnum = A[0];
        for (int i = 1; i < A.size(); i++) {
            if (A[i] < maxval) {
                cur = i;
                maxval = maxnum;
            }
            maxnum = max(A[i], maxnum);
        }
        return cur + 1;
    }
};
#endif //LEETCODE_LEETCODE_915_H
