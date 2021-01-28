//
// Created by panrenhua on 1/29/21.
//

#ifndef LEETCODE_UNIFIND_H
#define LEETCODE_UNIFIND_H

#include "allheaders.h"
class UniFind {
    vector<int> v;
    vector<int> sz;

    UniFind(int n) {
        v.resize(n, 0);
        sz.resize(n, 0);

        for (int i = 0; i < n; i++) {
            v[i] = i;
        }
    }
    int findRoot(int x) {
        return x == v[x] ? x : (v[x] = findRoot(v[x]));
    }
    bool Union(int x, int y){
        int rx = findRoot(x);
        int ry = findRoot(y);

        if (rx != ry) {
            v[rx] = ry;
            return true;
        }
        return false;
    }
};

#endif //LEETCODE_UNIFIND_H
