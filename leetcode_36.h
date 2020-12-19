//
// Created by panrenhua on 2020/12/20.
//

#ifndef LEETCODE_LEETCODE_36_H
#define LEETCODE_LEETCODE_36_H

#include "allheaders.h"
/** 36. 有效的数独
 * */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int f[9];
        for (int i = 0; i < 9; i++) {
            int j;
            memset(f, 0, 36);
            for (j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (f[board[i][j] - '1'] != 0) return false;
                else {
                    f[board[i][j] - '1'] = 1;
                }
            }
            memset(f, 0, 36);
            for (j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if (f[board[j][i] - '1'] != 0) return false;
                else {
                    f[board[j][i] - '1'] = 1;
                }
            }
            memset(f, 0, 36);
            for(int u = 0; u < 3; u++) {
                for(int v = 0; v < 3; v++) {
                    if (board[i / 3 * 3 + u][i % 3 * 3 + v] == '.') continue;
                    if (f[board[i / 3 * 3 + u][i % 3 * 3 + v] - '1'] != 0) return false;
                    else {
                        f[board[i / 3 * 3 + u][i % 3 * 3 + v] - '1'] = 1;
                    }
                }
            }
        }
        return true;
    }
};


#endif //LEETCODE_LEETCODE_36_H
