//
// Created by panrenhua on 2020/12/6.
//

#ifndef LEETCODE_LEETCODE_118_H
#define LEETCODE_LEETCODE_118_H

#include "allheaders.h"

/** 118. 杨辉三角
 *
 * */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);

        for (int i = 1; i <= numRows; i++) {
            ans[i - 1].resize(i);
            ans[i - 1][0] = ans[i - 1].back() = 1;
            if (i == 1 || i == 2) continue;
            for (int j = 1; j < i - 1; j++) {
                ans[i - 1][j] = ans[i - 2][j - 1] + ans[i - 2][j];
            }
        }

        return ans;
    }
};
#endif //LEETCODE_LEETCODE_118_H
