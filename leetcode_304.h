//
// Created by panrenhua on 1/22/21.
//

#ifndef LEETCODE_LEETCODE_304_H
#define LEETCODE_LEETCODE_304_H
#include "allheaders.h"
/** 304. 二维区域和检索 - 矩阵不可变
 * */
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        dp.resize(matrix.size() + 1);
        if (matrix.size() != 0) {
            for (auto& c : dp) c.resize(matrix[0].size() + 1, 0);

            for (int i = 1; i < dp.size(); i++) {
                for (int j = 1; j < dp[0].size(); j++) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] + dp[row1][col1] - dp[row2 + 1][col1] - dp[row1][col2 + 1];
    }
};


#endif //LEETCODE_LEETCODE_304_H
