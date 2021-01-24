//
// Created by panrenhua on 1/25/21.
//

#ifndef LEETCODE_LEETCODE_959_H
#define LEETCODE_LEETCODE_959_H

#include "allheaders.h"
/** 959. 由斜杠划分区域
 *
 * 并查集 统计边
 * 一个方格四条边 如果是 / 则 0,3; 1,2  分别连通
 * 如果是 \ 则 0,1; 2,3 连通
 * 最后统计正方形中的连通图个数
 * */
class Solution {
public:
    vector<int> dp;
    int findRoot(int k) {
        return k == dp[k] ? k : (dp[k] = findRoot(dp[k]));
    }
    void Union(int x, int y) {
        int r1 = findRoot(x);
        int r2 = findRoot(y);

        if (r1 != r2) {
            dp[r1] = r2;
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        dp.resize(2 * n * n + 2 * n);
        for (int i = 0; i < dp.size(); i++) {
            dp[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    Union(n * i + j, n * (n + 1) + n * j + i);
                    Union(n * (i + 1) + j, n * (n + 1) + n * (j + 1) + i);
                }else if (grid[i][j] == ' '){
                    Union(n * i + j, n * (n + 1) + n * j + i);
                    Union(n * (i + 1) + j, n * (n + 1) + n * (j + 1) + i);
                    Union(n * i + j, n * (i + 1) + j);
                }else {
                    Union(n * i + j, n * (n + 1) + n * (j + 1) + i);
                    Union(n * (i + 1) + j, n * (n + 1) + n * j + i);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < dp.size(); i++) {
            //cout << dp[i] << endl;
            if (dp[i] == i) {
                ans++;
            }
        }
        return ans;
    }
};


#endif //LEETCODE_LEETCODE_959_H
