//
// Created by panrenhua on 1/21/21.
//

#ifndef LEETCODE_LEETCODE_913_H
#define LEETCODE_LEETCODE_913_H

#include "allheaders.h"
/** 913. 猫和老鼠
 * 考验智商简直了......
 * bfs 边界条件是 x==y x==0 turn==2*n(这个最难想) 返回
 *
 * 还有一种 将所有边界情况插入一个队列 遍历队列找出所有情况
 * */
class Solution {
public:
    // x : mouse y : cat turn : 0/mouse 1/cat
    // return 0/平局 1/mouse 2/cat
    int n;
    int backtrace(int x, int y, int turn, vector<vector<int>>& g, vector<vector<vector<int>>>& dp) {
        if (turn == 2 * n) return dp[x][y][turn] = 0;
        if (x == 0) return dp[x][y][turn] = 1;
        if (x == y) return dp[x][y][turn] = 2;

        if (dp[x][y][turn] != -1) return dp[x][y][turn];
        int ans;
        if (turn % 2 == 1) {
            ans = 1;
            for (int i = 0; i < g[y].size(); i++) {
                if (g[y][i] == 0) continue;
                int next = backtrace(x, g[y][i], turn + 1, g, dp);
                if (next == 2) return dp[x][y][turn] = 2;
                if (next == 0) ans = 0;
            }
            return dp[x][y][turn] = ans;
        }else {
            ans = 2;
            for (int i = 0; i < g[x].size(); i++) {
                int next = backtrace(g[x][i], y, turn + 1, g, dp);
                if (next == 1) return dp[x][y][turn] = 1;
                if (next == 0) ans = 0;
            }
            return dp[x][y][turn] = ans;
        }
    }
    int catMouseGame(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2 * n + 1, -1)));
        backtrace(1, 2, 0, graph, dp);
        return dp[1][2][0];
    }
};

#endif //LEETCODE_LEETCODE_913_H
