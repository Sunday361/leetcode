//
// Created by panrenhua on 2020/12/9.
//

#ifndef LEETCODE_LEETCODE_980_H
#define LEETCODE_LEETCODE_980_H

#include "allheaders.h"

/** 980. 不同路径 III
 * */
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) cnt++;
            }
        }
    }
};
#endif //LEETCODE_LEETCODE_980_H
