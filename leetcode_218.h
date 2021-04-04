//
// Created by panrenhua on 4/3/21.
//

#ifndef LEETCODE_LEETCODE_218_H
#define LEETCODE_LEETCODE_218_H

#include "allheaders.h"
/** 218. 天际线问题
 * 转换为线段树问题, 对区间上的值, 更新其最大的高度, 区间更新方式
 * 然后query其每一个点的高度, 如果发生了变化, 则说明这是关键点
 * */
class Solution {
    vector<int> d;
    vector<int> lazy;

    void update(int nodel, int noder, int l, int r, int val, int id) {
        if (nodel >= l && noder <= r) {
            lazy[id] = max(val, lazy[id]);
            d[id] = max(d[id], lazy[id]);
            return;
        }
        int m = nodel + (noder - nodel) / 2;
        int son1 = 2 * id;
        int son2 = son1 + 1;
        if (lazy[id] && nodel != noder) {
            lazy[son1] = max(lazy[id], lazy[son1]);
            lazy[son2] = max(lazy[id], lazy[son2]);
            d[son1] = max(d[son1], lazy[son1]);
            d[son2] = max(d[son2], lazy[son2]);
            lazy[id] = 0;
        }
        if (l <= m) update(nodel, m, l, r, val, son1);
        if (r >= m + 1) update(m + 1, noder, l, r, val, son2);
        d[id] = max(d[son1], d[son2]);
    }

    int query(int nodel, int noder, int l, int r, int id) {
        if (nodel >= l && noder <= r) {
            return d[id];
        }
        int m = nodel + (noder - nodel) / 2;
        int son1 = 2 * id;
        int son2 = son1 + 1;
        if (lazy[id] && nodel != noder) {
            lazy[son1] = max(lazy[id], lazy[son1]);
            lazy[son2] = max(lazy[id], lazy[son2]);
            d[son1] = max(d[son1], lazy[son1]);
            d[son2] = max(d[son2], lazy[son2]);
            lazy[id] = 0;
        }
        int res = 0;
        if (l <= m) res = max(res, query(nodel, m, l, r, son1));
        if (r >= m + 1) res = max(res, query(m + 1, noder, l, r, son2));
        return res;
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        unordered_map<int,int> mpx;
        unordered_map<int,int> rmpx;
        int ranky = 1;
        int rankx = 1;
        set<int> stx;
        for (auto it : buildings) {
            stx.insert(it[0]);
            stx.insert(it[1]);
            stx.insert(it[1] - 1);
        }
        for (auto x : stx) {
            mpx[x] = rankx;
            rmpx[rankx] = x;
            rankx++;
        }
        d = vector<int> (rankx * 4 + 5);
        lazy = vector<int> (rankx * 4 + 5);

        rankx--;
        for (auto it : buildings) {
            update(1, rankx, mpx[it[0]], mpx[it[1] - 1], it[2], 1);
        }
        int before = -1;
        vector<vector<int>> res;
        for (int i = 1; i <= rankx; i++) {
            int cur = query(1, rankx, i, i, 1);
            if (cur != before)
                res.push_back({rmpx[i], cur});
            before = cur;
        }
        return res;
    }
};
#endif //LEETCODE_LEETCODE_218_H
