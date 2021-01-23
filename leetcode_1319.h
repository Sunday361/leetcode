//
// Created by panrenhua on 1/23/21.
//

#ifndef LEETCODE_LEETCODE_1319_H
#define LEETCODE_LEETCODE_1319_H

#include "allheaders.h"
/** 1319. 连通网络的操作次数
 * */
class Solution {
public:
    vector<int> f;
    int find(int k) {
        return k == f[k] ? k : (f[k] = find(f[k]));
    }
    bool Union(int x, int y) {
        int r1 = find(x);
        int r2 = find(y);

        if (r1 != r2) {
            f[r1] = r2;
            return true;
        }
        return false;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        f.resize(n, 0);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
        int cnt = 0;
        int left = 0;
        for (int i = 0; i < connections.size(); i++) {
            if (!Union(connections[i][0], connections[i][1])) {
                left++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (f[i] == i) {
                cnt++;
            }
        }

        if (cnt - 1 > left) return -1;
        else return cnt - 1;
    }
};

#endif //LEETCODE_LEETCODE_1319_H
