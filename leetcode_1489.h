//
// Created by panrenhua on 1/21/21.
//

#ifndef LEETCODE_LEETCODE_1489_H
#define LEETCODE_LEETCODE_1489_H

#include "allheaders.h"
/** 1489. 找到最小生成树里的关键边和伪关键边
 * 纯暴力破解
 * */
class Solution {
public:
    vector<int> f;
    vector<int> s;
    int findRoot(int k) {
        return k == f[k] ? k : (f[k] = findRoot(f[k]));
    }
    bool Union(int x, int y) {
        int r1 = findRoot(x);
        int r2 = findRoot(y);

        if (r1 != r2) {
            f[r1] = r2;
            return true;
        }else {
            return false;
        }
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ans(2, vector<int>());
        vector<int> index(edges.size(), 0);
        for (int i = 0; i < index.size(); i++) {
            index[i] = i;
        }
        sort(index.begin(), index.end(), [&](int a, int b) {
            return edges[index[a]][2] < edges[index[b]][2];
        });
        f.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }
        vector<int> p(edges.size(), 0);
        int count = 0;
        int mst = 0;
        // 求最小生成树
        for (int i = 0; i < index.size(); i++) {
            if (Union(edges[index[i]][0], edges[index[i]][1])) {
                count++;
                mst += edges[index[i]][2];
            }
            if (count == n - 1) break;
        }
        set<int> unique;
        for (int i = 0; i < index.size(); i++) {
            count = 0;
            int temp = 0;

            for (int j = 0; j < n; j++) {
                f[j] = j;
            }
            // 不包含此边
            set<int> q;
            for (int j = 0; j < index.size(); j++) {
                if (i == j) continue;
                if (Union(edges[index[j]][0], edges[index[j]][1])) {
                    q.insert(index[j]);
                    count++;
                    temp += edges[index[j]][2];
                }
                if (count == n - 1) break;
            }

            if (temp != mst || count != n - 1) {
                unique.insert(index[i]);
            } else if (temp == mst && count == n - 1){
                for (auto it = q.begin(); it != q.end(); it++) {
                    p[*it]++;
                }
            }

            // 包含此边 仅在 此边的使用次数为0 时使用
            if (unique.find(index[i]) == unique.end() && p[index[i]] == 0) {
                for (int j = 0; j < n; j++) {
                    f[j] = j;
                }
                count = 0;
                temp = 0;
                if (Union(edges[index[i]][0], edges[index[i]][1])) {
                    count++;
                    temp += edges[index[i]][2];
                }
                for (int j = 0; j < edges.size(); j++) {
                    if (Union(edges[index[j]][0], edges[index[j]][1])) {
                        count++;
                        temp += edges[index[j]][2];
                    }
                    if (count == n - 1) break;
                }
                if (temp == mst && count == n - 1) {
                    p[index[i]]++;
                }
            }
        }
        for (int i = 0; i < edges.size(); i++) {
            if (p[index[i]] != 0 && unique.find(index[i]) == unique.end()) {
                ans[1].push_back(index[i]);
            }else if (unique.find(index[i]) != unique.end()) {
                ans[0].push_back(index[i]);
            }
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_1489_H
