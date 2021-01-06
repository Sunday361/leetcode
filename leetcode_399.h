//
// Created by panrenhua on 1/6/21.
//

#ifndef LEETCODE_LEETCODE_399_H
#define LEETCODE_LEETCODE_399_H

#include "allheaders.h"
/** 399. 除法求值
 * 并查集 储存 root 以及和上一个的倍数值
 * */
class Solution {
public:
    map<string, pair<string, double>> m;
    pair<string, double> findRoot(string s) {
        if (m.find(s) == m.end()) return {"", -1};
        pair<string, double> p;
        double ans = 1.0;
        while(m.find(s) != m.end() && s != m[s].first) {
            ans *= m[s].second;
            s = m[s].first;
        }
        p.first = s;
        p.second = ans;
        return p;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int len = equations.size();
        vector<double> ans(queries.size(), 0);
        for (int i = 0; i < len; i++) {
            m.insert({equations[i][0], {equations[i][0], 1.0}});
            m.insert({equations[i][1], {equations[i][1], 1.0}});
            auto r1 = findRoot(equations[i][0]);
            auto r2 = findRoot(equations[i][1]);

            if (r1.first != r2.first) {
                m[r2.first].first = r1.first;
                m[r2.first].second = r1.second * values[i] / r2.second;
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            auto r1 = findRoot(queries[i][0]);
            auto r2 = findRoot(queries[i][1]);
            if (r1.first == "" || r2.first == "" || r1.first != r2.first) {
                ans[i] = -1.0;
            }else {
                ans[i] = r2.second / r1.second;
            }
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_399_H
