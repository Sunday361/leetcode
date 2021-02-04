//
// Created by panrenhua on 2/4/21.
//

#ifndef LEETCODE_LEETCODE_74_H
#define LEETCODE_LEETCODE_74_H

#include "allheaders.h"
/** 74. 搜索二维矩阵
 * */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0, right = matrix.size() - 1;
        while(right > left) {
            int mid = (left + right) / 2 + 1;
            if (matrix[mid][0] > target) {
                right = mid - 1;
            }else if (matrix[mid][0] < target) {
                left = mid;
            }else {
                return true;
            }
        }
        int r = left;
        left = 0; right = matrix[0].size() - 1;
        while(right > left) {
            int mid = (left + right) / 2;
            if (matrix[r][mid] > target) {
                right = mid - 1;
            }else if (matrix[r][mid] < target) {
                left = mid + 1;
            }else {
                return true;
            }
        }
        if (matrix[r][left] == target) return true;
        else return false;
    }
};
#endif //LEETCODE_LEETCODE_74_H
