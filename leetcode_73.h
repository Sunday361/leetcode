//
// Created by panrenhua on 1/21/21.
//

#ifndef LEETCODE_LEETCODE_73_H
#define LEETCODE_LEETCODE_73_H

#include "allheaders.h"
/** 73. 矩阵置零
 * 矩阵置零 将 [i, j] 所在的行列的头置为0, 随后扫描第一行和第一列
 * 注意特殊点 [0, 0] 即 i = 0 或 j = 0 时 需要额外考虑
 * */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int c = 0, r = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0 && i > 0 && j > 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }else if (matrix[i][j] == 0 && i == 0 && j > 0) {
                    r = 1;
                    matrix[0][j] = 0;
                }else if (matrix[i][j] == 0 && j == 0 && i > 0) {
                    c = 1;
                    matrix[i][0] = 0;
                }else if (matrix[i][j] == 0) {
                    c = r = 1;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                for (auto& n : matrix[i]) {
                    n = 0;
                }
            }
        }

        for (int i = 1; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                for (int j = 0; j < matrix.size(); j++) {
                    matrix[j][i] = 0;
                }
            }
        }
        if (c) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
        if (r) {
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }
    }
};
#endif //LEETCODE_LEETCODE_73_H
