//
// Created by panrenhua on 2020/12/26.
//

#ifndef LEETCODE_LEETCODE_85_H
#define LEETCODE_LEETCODE_85_H

#include "allheaders.h"
/** 85. 最大矩形
 * 将此题转换为第84题
 * 用一个单调栈保存着 第j个矩形之前的所有比自身小的矩形所对应的序号,当 当前矩形小于等于栈顶矩形时
 * 将栈顶出栈 并将其可以到达的最右边赋值为 j
 * 最后 计算所有heights 所对应的 最左和最右 (right[i] - left[i] - 1) * heights[i] 求其中的最大值
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
