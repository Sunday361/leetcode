//
// Created by panrenhua on 2020/12/17.
//

#ifndef LEETCODE_LEETCODE_502_H
#define LEETCODE_LEETCODE_502_H

#include "allheaders.h"

/** 502. IPO
 * 一个单调队列
 * */

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        auto expr = [&](int x, int y) {
            if (Profits[x] != Profits[y]) return Profits[x] < Profits[y];
            else return Capital[x] < Capital[y];
        };
        vector<int> flags(Profits.size(), 0);
        for (int i = 0; i < flags.size(); i++) {
            flags[i] = i;
        }

        sort(flags.begin(), flags.end(), [&](int x, int y){
            return Capital[x] < Capital[y];
        });
        priority_queue<int, vector<int>, decltype(expr)> q{expr};
        int ans = W;
        int index = 0;
        while(k) {
            for (index; index < flags.size() && Capital[flags[index]] <= ans; index++) {
                q.push(flags[index]);
            }

            if (q.empty()) break;
            int f = q.top();
            q.pop();

            ans += Profits[f];
            k--;
        }

        return ans;
    }
};

#endif //LEETCODE_LEETCODE_502_H
