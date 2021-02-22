//
// Created by panrenhua on 2/22/21.
//

#ifndef LEETCODE_LEETCODE_766_H
#define LEETCODE_LEETCODE_766_H

#include "allheaders.h"
/** 766. 托普利茨矩阵
 * */
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int nx = i - 1;
                int ny = j - 1;
                if (nx >= 0 && ny >= 0 && matrix[i][j] != matrix[nx][ny]) {
                    return false;
                }
            }
        }
        return true;
    }
};
#endif //LEETCODE_LEETCODE_766_H
