//
// Created by panrenhua on 1/7/21.
//

#ifndef LEETCODE_LEETCODE_547_H
#define LEETCODE_LEETCODE_547_H

#include "allheaders.h"
/** 547. 省份数量
 * 并查集
 * */
class Solution {
public:
    vector<int> m;
    int findRoot(int k) {
        while(k != m[k]) {
            k = m[k];
        }
        return k;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        m.resize(len);
        for (int i = 0; i < len; i++) {
            m[i] = i;
        }

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int r1 = findRoot(i);
                int r2 = findRoot(j);

                if (r1 != r2 && isConnected[i][j]) {
                    m[r2] = r1;
                }
            }
        }
        int ans = 0;
        set<int> r;
        for (int i = 0; i < len; i++) {
            r.insert(findRoot(i));
        }
        return r.size();
    }
};

#endif //LEETCODE_LEETCODE_547_H
