//
// Created by panrenhua on 1/13/21.
//

#ifndef LEETCODE_LEETCODE_240_H
#define LEETCODE_LEETCODE_240_H

#include "allheaders.h"
/** 240. 搜索二维矩阵 II
 * 从左下 或者 右上角看 这个矩阵实际上是一个 二叉搜索树
 * */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();

        int x = m - 1, y = 0;

        while(x >= 0 && y < n) {
            if (matrix[x][y] == target) {
                return true;
            }else if (matrix[x][y] < target) {
                y++;
            }else {
                x--;
            }
        }
        return false;
    }
};

#endif //LEETCODE_LEETCODE_240_H
