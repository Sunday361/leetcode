//
// Created by panrenhua on 3/3/21.
//

#ifndef LEETCODE_LEETCODE_440_H
#define LEETCODE_LEETCODE_440_H

#include "allheaders.h"
/** 440. 字典序的第K小数字
 * */
class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;//初始化为cur = 1，k需要自减1
        while (k > 0) {
            long long step = 0, first = cur, last = cur + 1;
            //统计这棵子树下所有节点数（step）
            while (first <= n) {
                step += min((long long)n + 1, last) - first;//不能超过n的值，并不是所有节点都有十个子节点
                first *= 10;
                last *= 10;
            }
            if (step <= k) {//不在子树中
                ++cur;
                k -= step;
            }
            else {//在子树中，进入子树
                cur *= 10;
                --k;
            }
        }
        return cur;
    }
};


#endif //LEETCODE_LEETCODE_440_H
