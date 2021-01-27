//
// Created by panrenhua on 1/27/21.
//

#ifndef LEETCODE_LEETCODE_1579_H
#define LEETCODE_LEETCODE_1579_H

#include "allheaders.h"
/** 1579. 保证图可完全遍历
 * */
class Solution {
public:
    vector<int> a;
    vector<int> b;

    int findRoot(vector<int>& f, int k) {
        return k == f[k] ? k : (f[k] = findRoot(f, f[k]));
    }
    bool Union(int x, int y, vector<int>& f) {
        int r1 = findRoot(f, x);
        int r2 = findRoot(f, y);

        if (r1 != r2) {
            f[r1] = r2;
            return true;
        }
        return false;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int count = 0;
        int counta = 0, countb = 0;
        a.resize(n + 1);
        b.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            a[i] = b[i] = i;
        }
        for (auto& e : edges) {
            if (e[0] == 3) {
                bool ua = Union(e[1], e[2], a);
                bool ub = Union(e[1], e[2], b);
                if (!ua && !ub) {
                    count++;
                }else {
                    counta++;
                    countb++;
                }
            }
        }
        // alice
        for (auto& e : edges) {
            if (e[0] == 1) {
                if (!Union(e[1], e[2], a)) {
                    count++;
                }else {
                    counta++;
                }
            }
        }
        // bob
        for (auto& e : edges) {
            if (e[0] == 2) {
                if (!Union(e[1], e[2], b)) {
                    count++;
                }else {
                    countb++;
                }
            }
        }
        //cout << counta << countb << endl;
        if (countb != n - 1 || counta != n - 1) return -1;
        return count;
    }
};
#endif //LEETCODE_LEETCODE_1579_H
