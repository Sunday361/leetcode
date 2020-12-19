//
// Created by panrenhua on 2020/12/19.
//

#ifndef LEETCODE_LEETCODE_48_H
#define LEETCODE_LEETCODE_48_H
#include "allheaders.h"
/** 48. 旋转图像
 * */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix, int x, int y) {
        if (x >= y) {
            return;
        }else {
            int len = y - x;
            for (int i = 0; i < len; i++) {
                int temp = matrix[x][x + i];
                matrix[x][x + i] = matrix[y - i][x];
                matrix[y - i][x] = matrix[y][y - i];
                matrix[y][y - i] = matrix[x + i][y];
                matrix[x + i][y] = temp;
            }
            rotate(matrix, x + 1, y - 1);
            return;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        rotate(matrix, 0, matrix.size() - 1);
    }
};

#endif //LEETCODE_LEETCODE_48_H
