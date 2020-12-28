//
// Created by panrenhua on 12/27/20.
//

#ifndef LEETCODE_LEETCODE_WEEKLY_CONTEST_221_H
#define LEETCODE_LEETCODE_WEEKLY_CONTEST_221_H

#include "allheaders.h"

class Solution {
public:
    /** 5638. 吃苹果的最大数目
     * 用一个优先队列存苹果以及天数
     * 当q不为空时 或者 date < n 时循环, 当过期日期小于等于当前日期 则出队
     * */
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        auto cmp = [](pair<int, int>& x, pair<int, int>& y) {
            return x.first > y.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q{cmp};
        int ans = 0;
        int date = 0;
        while(date < n || !q.empty()) {
            while(!q.empty() && q.top().first <= date) {
                q.pop();
            }
            if (date < n && apples[date] != 0 && days[date] != 0) {
                pair<int, int> p{date + days[date], apples[date]};
                q.push(p);
            }
            if (!q.empty()) {
                auto top = q.top();
                q.pop();
                top.second--;
                ans++;
                if (top.second > 0) {
                    q.push(top);
                }
            }
            ++date;
        }
        return ans;
    }
    /** 5210. 球会落何处
     * 简单动态规划, 根据上一次状态求下次
     * */
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<int> ans(n, -1);
        if (n == 1) return ans;
        for (int i = 0; i < n; i++) {
            ans[i] = i;
        }

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, -1);
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    if (grid[i][j] == -1 && grid[i][j + 1] == -1) {
                        temp[j] = ans[j + 1];
                    }
                }else if (j == n - 1) {
                    if (grid[i][j] == 1 && grid[i][j - 1] == 1) {
                        temp[j] = ans[j - 1];
                    }
                }else {
                    if (grid[i][j] == 1 && grid[i][j - 1] == 1) {
                        temp[j] = ans[j - 1];
                    }else if (grid[i][j] == -1 && grid[i][j + 1] == -1) {
                        temp[j] = ans[j + 1];
                    }
                }
            }
            ans = temp;
        }
        vector<int> result(n, -1);
        for (int i = 0; i < n; i++) {
            if (ans[i] != -1) result[ans[i]] = i;
        }
        return result;
    }
    /** 5640. 与数组中元素的最大异或值
     * */
};

#endif //LEETCODE_LEETCODE_WEEKLY_CONTEST_221_H
