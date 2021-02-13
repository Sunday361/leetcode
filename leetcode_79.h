//
// Created by panrenhua on 2/13/21.
//

#ifndef LEETCODE_LEETCODE_79_H
#define LEETCODE_LEETCODE_79_H

#include "allheaders.h"
/** 79. 单词搜索
 * 暴力搜素
 * */
class Solution {
public:
    bool dfs(vector<vector<bool>>& visit, vector<vector<char>>& board, int a, int b, string& word, int size) {
        if (word.size() == size) return true;
        if (a < 0 || b < 0 || a >= board.size() || b >= board[0].size() || word[size] != board[a][b])
            return false;
        if (visit[a][b] == 0) {
            visit[a][b] = true;

            if (dfs(visit, board, a + 1, b, word, size + 1)
                || dfs(visit, board, a, b + 1, word, size + 1)
                || dfs(visit, board, a - 1, b, word, size + 1)
                || dfs(visit, board, a, b - 1, word, size + 1)) {
                return true;
            }

            visit[a][b] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> v(board.size(), vector<bool>(board[0].size(), 0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (dfs(v, board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};
#endif //LEETCODE_LEETCODE_79_H
