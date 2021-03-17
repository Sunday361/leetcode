//
// Created by panrenhua on 3/17/21.
//

#ifndef LEETCODE_LEETCODE_815_H
#define LEETCODE_LEETCODE_815_H
#include "allheaders.h"
/** 815. 公交路线
 * */
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (target == source) return 0;
        map<int, vector<int>> stations;

        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                stations[routes[i][j]].push_back(i);
            }
        }
        vector<int> flags(routes.size(), -1);
        queue<int> q;
        q.push(source);
        int level = 1;
        while (!q.empty()) {
            int l = q.size();
            for (int u = 0; u < l; u++) {
                int f = q.front();
                q.pop();
                for (int i = 0; i < stations[f].size(); i++) {
                    if (flags[stations[f][i]] != -1) continue;
                    flags[stations[f][i]] = 1;
                    for (int j = 0; j < routes[stations[f][i]].size(); j++) {
                        if (routes[stations[f][i]][j] == target) return level;
                        q.push(routes[stations[f][i]][j]);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
#endif //LEETCODE_LEETCODE_815_H
