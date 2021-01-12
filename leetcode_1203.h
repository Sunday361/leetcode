//
// Created by panrenhua on 1/12/21.
//

#ifndef LEETCODE_LEETCODE_1203_H
#define LEETCODE_LEETCODE_1203_H

#include "allheaders.h"
/** 1203. 项目管理
 * top order between groups and next in every group
 * */
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < group.size(); i++) {
            if (group[i] == -1) {
                group[i] = m++;
            }
        }
        vector<int> gd(m, 0);
        vector<set<int>> g(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < beforeItems[i].size(); j++) {
                if (g[group[beforeItems[i][j]]].find(group[i]) != g[group[beforeItems[i][j]]].end() || group[beforeItems[i][j]] == group[i]) continue;
                gd[group[i]]++;
                g[group[beforeItems[i][j]]].insert(group[i]);
            }
        }
        /** top order between groups and store its result in bq if there is an answer */
        queue<int> q;
        vector<int> bq;
        for (int i = 0; i < gd.size(); i++) {
            if (gd[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            bq.push_back(f);
            count++;
            for (auto it = g[f].begin(); it != g[f].end(); it++) {
                if (gd[*it] != 0) {
                    gd[*it]--;
                    if (gd[*it] == 0) {
                        q.push(*it);
                    }
                }
            }
        }
        if (count != gd.size()) return {};

        vector<set<int>> t(n);
        vector<int> td(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < beforeItems[i].size(); j++) {
                t[beforeItems[i][j]].insert(i);
                td[i]++;
            }
        }
        map<int, vector<int>> mtd;
        for (int i = 0; i < n; i++) {
            mtd[group[i]].push_back(i);
        }
        vector<int> ans;
        /** use the groups' top order to judge if the top order in one group is hold */
        for (int u = 0; u < bq.size(); u++) {
            queue<int> q;
            for (int i = 0; i < mtd[bq[u]].size(); i++) {
                if (td[mtd[bq[u]][i]] == 0) {
                    q.push(mtd[bq[u]][i]);
                }
            }
            int count = 0;
            while(!q.empty()) {
                int f = q.front();
                q.pop();
                ans.push_back(f);
                count++;
                for (auto it = t[f].begin(); it != t[f].end(); it++) {
                    if (td[*it] != 0) {
                        td[*it]--;
                        if (td[*it] == 0 && group[*it] == bq[u]) {
                            q.push(*it);
                        }
                    }
                }
            }
            if (count != mtd[bq[u]].size()) {
                return {};
            }
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_1203_H
