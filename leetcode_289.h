//
// Created by panrenhua on 3/17/21.
//

#ifndef LEETCODE_LEETCODE_289_H
#define LEETCODE_LEETCODE_289_H
#include "allheaders.h"
/** 289. 生命游戏
 * 用额外的位来存储 原来的状态, 用新的位存储新的状态
*/
class Solution {
public:
    vector<vector<int>> dir{{1,0},{-1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = dir[k][0] + i;
                    int ny = dir[k][1] + j;

                    if (nx >= 0 && ny >= 0 && nx < m && ny < n && (board[nx][ny] & 1) == 1) {
                        count++;
                    }
                }

                if (board[i][j] == 1) {
                    if (count >= 2 && count <= 3) {
                        board[i][j] |= 2;
                    }
                } else {
                    if (count == 3) {
                        board[i][j] |= 2;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};
#endif //LEETCODE_LEETCODE_289_H
