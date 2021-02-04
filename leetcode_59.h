//
// Created by panrenhua on 2/4/21.
//

#ifndef LEETCODE_LEETCODE_59_H
#define LEETCODE_LEETCODE_59_H

#include "allheaders.h"
/** 59. 螺旋矩阵 II
 * */
class Solution {
public:
    enum {r = 0, d = 1, u = 2, l = 3};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int x = 0, y = 0;
        int pos = 1;
        int direction = r;
        while(pos <= n * n) {
            ans[x][y] = pos;
            pos++;
            switch (direction) {
                case r:
                    if (y + 1 < n && ans[x][y + 1] == 0) {
                        y = y + 1;
                    }else {
                        x = x + 1;
                        direction = d;
                    }
                    break;
                case l:
                    if (y - 1 >= 0 && ans[x][y - 1] == 0) {
                        y = y - 1;
                    }else {
                        x = x - 1;
                        direction = u;
                    }
                    break;
                case u:
                    if (x - 1 >= 0 && ans[x - 1][y] == 0) {
                        x = x - 1;
                    }else {
                        y = y + 1;
                        direction = r;
                    }
                    break;
                case d:
                    if (x + 1 < n && ans[x + 1][y] == 0) {
                        x = x + 1;
                    }else {
                        y = y - 1;
                        direction = l;
                    }
                    break;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_59_H
