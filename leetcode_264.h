//
// Created by panrenhua on 2/22/21.
//

#ifndef LEETCODE_LEETCODE_264_H
#define LEETCODE_LEETCODE_264_H

#include "allheaders.h"
/** 264. 丑数 II
 *
 * i2 i3 i5 分别指向 乘2,3,5的元素,新的元素必定是由已有的丑数 乘上2,3,5得来的
 * */
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n, INT_MAX);
        ans[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; i++) {
            ans[i] = min(min(ans[i2] * 2, ans[i3] * 3), ans[i5] * 5);
            /** 这里千万不要用 else if 因为 min 会出现重复数字
             * */
            if (ans[i] == ans[i2] * 2) {
                i2++;
            }
            if (ans[i] == ans[i3] * 3) {
                i3++;
            }
            if (ans[i] == ans[i5] * 5) {
                i5++;
            }
        }
        return ans[n - 1];
    }
};
#endif //LEETCODE_LEETCODE_264_H
