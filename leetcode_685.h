//
// Created by panrenhua on 1/13/21.
//

#ifndef LEETCODE_LEETCODE_685_H
#define LEETCODE_LEETCODE_685_H

#include "allheaders.h"
/** 685. 冗余连接 II
 * cv 大法好  !!!!!!
 * 先判 入度为 2 如果没有入度为2 说明成环了
 * ps: 自己四个月前写的贴在下面 ,根本看不懂自己写的啥
 * */
class Solution {
private:
    static const int N = 1010; // 如题：二维数组大小的在3到1000范围内
    int father[N];
    int n; // 边的数量
    // 并查集初始化
    void init() {
        for (int i = 1; i <= n; ++i) {
            father[i] = i;
        }
    }
    // 并查集里寻根的过程
    int find(int u) {
        return u == father[u] ? u : father[u] = find(father[u]);
    }
    // 将v->u 这条边加入并查集
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return ;
        father[v] = u;
    }
    // 判断 u 和 v是否找到同一个根
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
    // 在有向图里找到删除的那条边，使其变成树
    vector<int> getRemoveEdge(const vector<vector<int>>& edges) {
        init(); // 初始化并查集
        for (int i = 0; i < n; i++) { // 遍历所有的边
            if (same(edges[i][0], edges[i][1])) { // 构成有向环了，就是要删除的边
                return edges[i];
            }
            join(edges[i][0], edges[i][1]);
        }
        return {};
    }

    // 删一条边之后判断是不是树
    bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, int deleteEdge) {
        init(); // 初始化并查集
        for (int i = 0; i < n; i++) {
            if (i == deleteEdge) continue;
            if (same(edges[i][0], edges[i][1])) { // 构成有向环了，一定不是树
                return false;
            }
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }
public:

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int inDegree[N] = {0}; // 记录节点入度
        n = edges.size(); // 边的数量
        for (int i = 0; i < n; i++) {
            inDegree[edges[i][1]]++; // 统计入度
        }
        vector<int> vec; // 记录入度为2的边（如果有的话就两条边）
        // 找入度为2的节点所对应的边，注意要倒叙，因为优先返回最后出现在二维数组中的答案
        for (int i = n - 1; i >= 0; i--) {
            if (inDegree[edges[i][1]] == 2) {
                vec.push_back(i);
            }
        }
        // 处理图中情况1 和 情况2
        // 如果有入度为2的节点，那么一定是两条边里删一个，看删哪个可以构成树
        if (vec.size() > 0) {
            if (isTreeAfterRemoveEdge(edges, vec[0])) {
                return edges[vec[0]];
            } else {
                return edges[vec[1]];
            }
        }
        // 处理图中情况3
        // 明确没有入度为2的情况，那么一定有有向环，找到构成环的边返回就可以了
        return getRemoveEdge(edges);

    }
};
/** 四个月前写的 啥跟啥啊这是 ......
 * */
class MySolution {
public:
    int findRoot(vector<int>& tree, int k) {
        unordered_set<int> s;

        while (tree[k] != -1 && s.find(k) == s.end()) {
            s.insert(k);
            k = tree[k];
        }
        return k;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size(), f = -1, t = -1, root = 0;
        vector<int> tree(n + 1, -1);
        for (auto& e : edges) {
            if (tree[e[1]] == -1)
                tree[e[1]] = e[0];
            else {
                f = e[0];
                t = e[1];
            }
        }
        if (f == -1) {
            for (int i = n - 1; i >= 0; i--) {
                int u = edges[i][0], v = edges[i][1], j;
                tree[v] = -1;
                for (j = 1; j <= n; j++) {
                    if (findRoot(tree, j) != v)break;
                }
                tree[v] = u;
                if (j == n + 1) return edges[i];
            }
        }
        else {
            root = findRoot(tree, 1);
            for (int i = 2; i <= n; i++) {
                if (findRoot(tree, i) != root) {
                    return { tree[t], t };
                }
            }
            return { f, t };
        }
        return edges[0];
    }
};

#endif //LEETCODE_LEETCODE_685_H
