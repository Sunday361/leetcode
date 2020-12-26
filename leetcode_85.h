//
// Created by panrenhua on 2020/12/26.
//

#ifndef LEETCODE_LEETCODE_85_H
#define LEETCODE_LEETCODE_85_H

#include "allheaders.h"
/** 85. 最大矩形
 * */
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1' && heights[j] != 0) {
                    heights[j] = heights[j] + 1;
                }else if (matrix[i][j] == '1') {
                    heights[j] = 1;
                }else if (matrix[i][j] == '0') {
                    heights[j] = 0;
                }
            }

            vector<int> left(n, 0);
            vector<int> right(n, n);
            vector<int> stack;
            for (int j = 0; j < n; j++) {
                while(stack.size() != 0 && heights[j] <= heights[stack.back()]) {
                    right[stack.back()] = j;
                    stack.pop_back();
                }
                left[j] = (stack.empty() ? -1 : stack.back());
                stack.push_back(j);
            }

            int ans = 0;
            for (int j = 0; j < n; j++) {
                ans = max(ans, (right[j] - left[j] - 1) * heights[j]);
            }
            result = max(ans, result);
        }
        return result;
    }
};
#endif //LEETCODE_LEETCODE_85_H
