//
// Created by panrenhua on 3/17/21.
//

#ifndef LEETCODE_LEETCODE_554_H
#define LEETCODE_LEETCODE_554_H
#include "allheaders.h"
/** 554. 砖墙
 * */
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size(), c = 0;
        int ans = n;
        auto cmp = [&](vector<int>& p1, vector<int>& p2) {
            return p1[2] < p2[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q{cmp};

        for (int i = 0; i < n; i++) {
            q.push({i, 0, wall[i][0]});
        }

        for (int i = 0; i < wall[0].size(); i++) {
            c += wall[0][i];
        }

        while (!q.empty() && q.top()[2] != c) {
            int count = 1;
            auto f = q.top();
            q.pop();
            while (!q.empty() && q.top()[2] == f[2]) {
                auto temp = q.top();
                q.pop();
                temp[1]++;
                temp[2] += wall[temp[0]][temp[1]];
                q.push(temp);
                count++;
            }
            f[1]++;
            f[2] += wall[f[0]][f[1]];
            q.push(f);

            ans = min(n - count, ans);
        }
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_554_H
