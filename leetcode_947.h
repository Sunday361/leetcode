//
// Created by panrenhua on 1/15/21.
//

#ifndef LEETCODE_LEETCODE_947_H
#define LEETCODE_LEETCODE_947_H

#include "allheaders.h"
/** 947. 移除最多的同行或同列石头
 * */
class Solution {
public:
    vector<int> f = vector<int>(1001, 0);
    int findRoot(int k) {
        return k == f[k] ? k : (f[k] == findRoot(f[k]));
    }
    int removeStones(vector<vector<int>>& stones) {
        for (int i = 0; i < 1001; i++) {
            f[i] = i;
        }
        for (int i = 0; i < stones.size(); i++) {
            for (int j = i + 1; j < stones.size(); j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    int r1 = findRoot(i);
                    int r2 = findRoot(j);

                    if (r1 != r2) {
                        f[r1] = r2;
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < stones.size(); i++) {
            if (f[i] == i) {
                count++;
            }
        }
        return count;
    }
};

#endif //LEETCODE_LEETCODE_947_H
