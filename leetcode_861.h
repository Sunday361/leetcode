//
// Created by panrenhua on 2020/12/7.
//

#ifndef LEETCODE_LEETCODE_861_H
#define LEETCODE_LEETCODE_861_H

/**
 * 861. 翻转矩阵后的得分
 * */
#include "allheaders.h"

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int c = A.size(), r = A[0].size();
        int ans = 0;
        for (int i = 0; i < c; i++) {
            if (A[i][0] == 0) {
                for (int j = 0; j < r; j++) {
                    A[i][j] = A[i][j] == 1? 0: 1;
                }
            }
        }
        ans += c * (1 << (r - 1));
        for (int i = r - 1; i >= 1; i--) {
            int count = 0;
            for (int j = 0; j < c; j++) {
                if (A[j][i] == 1) count++;
            }
            if (count < c / 2) {
                count = c - count;
            }

            ans += count * (1 << (r - 1 - i));
        }

        return ans;
    }
};

#endif //LEETCODE_LEETCODE_861_H
