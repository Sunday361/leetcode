//
// Created by panrenhua on 3/5/21.
//

#ifndef LEETCODE_LEETCODE_37_H
#define LEETCODE_LEETCODE_37_H
#include "allheaders.h"
class Solution {
private:
    vector<char> judge(int x, int y, vector<vector<char>>& board) {
        vector<char> v;
        unordered_set<char> s;
        for (int i = 0; i < 9; i++) {
            s.insert(board[x][i]);
            s.insert(board[i][y]);
        }
        for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++) {
            for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++) {
                s.insert(board[i][j]);
            }
        }
        for (int i = 1; i <= 9; i++) {
            if (s.find('0' + i) == s.end()) {
                v.push_back('0' + i);
            }
        }
        return v;
    }
    bool solveSon(vector<vector<char>>& board, int x, int y) {
        if (x >= 9 || y >= 9) return true;
        if (board[x][y] == '.') {
            vector<char> v = judge(x, y, board);
            if (v.size() == 0) return false;
            for (int i = 0; i < v.size(); i++) {
                board[x][y] = v[i];
                if (y + 1 < 9) {
                    if (solveSon(board, x, y + 1) == true)
                        return true;
                }
                else {
                    if (solveSon(board, x + 1, 0) == true)
                        return true;
                }
                board[x][y] = '.';
            }
        }
        else {
            if (y + 1 < 9) {
                if (solveSon(board, x, y + 1) == true)
                    return true;
            }
            else {
                if (solveSon(board, x + 1, 0) == true)
                    return true;
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    solveSon(board, i, j);
            }
        }
    }
};
#endif //LEETCODE_LEETCODE_37_H
