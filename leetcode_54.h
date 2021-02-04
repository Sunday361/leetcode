//
// Created by panrenhua on 2/4/21.
//

#ifndef LEETCODE_LEETCODE_54_H
#define LEETCODE_LEETCODE_54_H

#include "allheaders.h"
/** 54. 螺旋矩阵
 * */
class Solution {
public:
    void spiralOrder(vector<int>& ans, vector<vector<int>>& matrix, int x1, int x2, int y1, int y2) {
        if (x1 > x2 || y1 > y2) return;
        if (x1 == x2) {
            for (int i = y1; i <= y2; i++) {
                ans.push_back(matrix[x1][i]);
            }
            return;
        }
        if (y1 == y2) {
            for (int i = x1; i <= x2; i++) {
                ans.push_back(matrix[i][y1]);
            }
            return;
        }
        for (int i = y1; i < y2; i++) {
            ans.push_back(matrix[x1][i]);
        }
        for (int i = x1; i < x2; i++) {
            ans.push_back(matrix[i][y2]);
        }
        for (int i = y2; i > y1; i--) {
            ans.push_back(matrix[x2][i]);
        }
        for (int i = x2; i > x1; i--) {
            ans.push_back(matrix[i][y1]);
        }
        spiralOrder(ans, matrix, x1 + 1, x2 - 1, y1 + 1, y2 - 1);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        spiralOrder(ans, matrix, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_54_H
