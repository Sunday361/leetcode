//
// Created by panrenhua on 1/13/21.
//

#ifndef LEETCODE_LEETCODE_684_H
#define LEETCODE_LEETCODE_684_H

#include "allheaders.h"
/** 684. 冗余连接
 * 并查集~~~
 * */
class Solution {
public:
    vector<int> v;
    int findRoot(int k) {
        return k == v[k] ? k : (v[k] = findRoot(v[k]));
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        v.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            v[i] = i;
        }

        for (int i = 0; i < edges.size(); i++) {
            int r1 = findRoot(edges[i][0]);
            int r2 = findRoot(edges[i][1]);
            if (r1 == r2) {
                return edges[i];
            }else{
                v[r1] = r2;
            }
        }
        return {};
    }
};
#endif //LEETCODE_LEETCODE_684_H
