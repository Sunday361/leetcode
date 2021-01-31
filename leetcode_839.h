//
// Created by panrenhua on 1/31/21.
//

#ifndef LEETCODE_LEETCODE_839_H
#define LEETCODE_LEETCODE_839_H

#include "allheaders.h"
/** 839. 相似字符串组
 * */
class Solution {
public:
    class UniFind {
    public:
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
        bool isConnect(int x, int y) {
            return findRoot(x) == findRoot(y);
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
    bool isSimilar(string& a, string& b){
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) count++;
        }
        if (count == 2 || count == 0) return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        UniFind uf(strs.size());

        for (int i = 1; i < strs.size(); i++) {
            for (int j = 0; j < i; j++){
                if (!uf.isConnect(i, j) && isSimilar(strs[i], strs[j])) {
                    uf.Union(i, j);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < strs.size(); i++) {
            if (uf.v[i] == i) count++;
        }
        return count;
    }
};
#endif //LEETCODE_LEETCODE_839_H
