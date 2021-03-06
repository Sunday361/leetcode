//
// Created by panrenhua on 4/3/21.
//

#ifndef LEETCODE_DATA_STRUCTURE_H
#define LEETCODE_DATA_STRUCTURE_H
#include "allheaders.h"
/** sort
 * */
void down(vector<int>& v, int i, int l) {
    int k = i;
    if (2 * i + 1 < l && v[2 * i + 1] > v[i]) k = 2 * i + 1;
    if (2 * i + 2 < l && v[2 * i + 2] > v[i] && v[2 * i + 2] > v[2 * i + 1]) k = 2 * i + 2;

    if (k != i) {
        swap(v[i], v[k]);
        down(v, k, l);
    }
}

void heapsort(vector<int>& v) {
    for (int i = v.size() / 2; i >= 0; i--) {
        down(v, i, v.size());
    }
    int l = v.size();
    while(l) {
        swap(v[0], v[l - 1]);
        l--;
        down(v, 0, l);
    }
}

void quicksort(vector<int>& v, int lo, int hi) {
    if (lo < hi) {
        int i = lo, j = hi;
        int pos = v[lo];
        while (i < j) {
            while (i < j && v[j] >= pos) j--;
            swap(v[i], v[j]);
            while (i < j && v[i] <= pos) i++;
            swap(v[i], v[j]);
        }
        v[i] = pos;

        quicksort(v, lo, i - 1);
        quicksort(v, i + 1, hi);
    }
}

/** 查找
 * */
int lower(vector<int>& v, int k) {
    int i = 0, j = v.size();

    while (i < j) {
        int mid = i + (j - i)/2;

        if (v[mid] < k) {
            i = mid + 1;
        }else {
            j = mid;
        }
    }

    return i;
}

int upper(vector<int>& v, int k) {
    int i = 0, j = v.size();

    while (i < j) {
        int mid = i + (j - i)/2;

        if (v[mid] <= k) {
            i = mid + 1;
        }else {
            j = mid;
        }
    }

    return i;
}

int findK(vector<int>& v, int lo, int hi, int k) {
    if (lo <= hi) {
        int i = lo, j = hi;
        int pos = v[lo];
        while (i < j) {
            while (i < j && v[j] >= pos) j--;
            swap(v[i], v[j]);
            while (i < j && v[i] <= pos) i++;
            swap(v[i], v[j]);
        }
        v[i] = pos;

        if (i < k) {
            return findK(v, i + 1, hi, k);
        }else if (i > k) {
            return findK(v, lo, i - 1, k);
        }else {
            return v[i];
        }
    }
    return -1;
}

/** 线段树
 * */

class SegmentTree{
public:
    vector<int> arr_;
    vector<int> tree_;
    SegmentTree(vector<int>&& arr) {
        arr_ = arr;
        tree_.resize(arr.size() * 4, 0);
    }

    void buildTree() {
        buildTree(0, 0, arr_.size() - 1);
    }

    void updateTree(int index, int val) {
        updateTree(0, 0, arr_.size() - 1, index, val);
    }

    int queryTree(int l, int r) {
        return queryTree(0, 0, arr_.size() - 1, l, r);
    }
    // 查询区间
    int queryTree(int node, int start, int end, int l, int r) {
        if (start > r || l > end) {
            return 0;
        }else if (start == end) {
            return tree_[node];
        }else if (start >= l && end <= r){
            return tree_[node];
        }

        int mid = start + (end - start) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        int sum_left = queryTree(left_node, start, mid, l, r);
        int sum_right = queryTree(right_node, mid + 1, end, l, r);

        return sum_left + sum_right;
    }
    // 构建树
    void buildTree(int node, int start, int end) {
        if (start == end) {
            tree_[node] = arr_[start];
            return;
        }
        int mid = start + (end - start) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;

        buildTree(left_node, start, mid);
        buildTree(right_node, mid + 1, end);

        tree_[node] = tree_[left_node] + tree_[right_node];
    }
    // 更新树
    void updateTree(int node, int start, int end, int index, int val) {
        if (start == end) {
            arr_[index] = val;
            tree_[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        if (index >= start && index <= mid) {
            updateTree(left_node, start, mid, index, val);
        }else {
            updateTree(right_node, mid + 1, end, index, val);
        }

        tree_[node] = tree_[left_node] + tree_[right_node];
    }
};

namespace st{
    vector<int> a;
    vector<int> d;
    vector<int> b;
    void build(int s, int t, int p) {
        // 对 [s,t] 区间建立线段树,当前根的编号为 p
        if (s == t) {
            d[p] = a[s];
            return;
        }
        int m = (s + t) / 2;
        build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
        // 递归对左右区间建树
        d[p] = d[p * 2] + d[(p * 2) + 1];
    }

    void update(int l, int r, int c, int s, int t, int p) {
        // [l,r] 为修改区间,c 为被修改的元素的变化量,[s,t] 为当前节点包含的区间,p
        // 为当前节点的编号
        if (l <= s && t <= r) {
            d[p] += (t - s + 1) * c, b[p] += c;
            return;
        }  // 当前区间为修改区间的子集时直接修改当前节点的值,然后打标记,结束修改
        int m = (s + t) / 2;
        if (b[p] && s != t) {
            // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
            d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
            b[p * 2] += b[p], b[p * 2 + 1] += b[p];  // 将标记下传给子节点
            b[p] = 0;                                // 清空当前节点的标记
        }
        if (l <= m) update(l, r, c, s, m, p * 2);
        if (r > m) update(l, r, c, m + 1, t, p * 2 + 1);
        d[p] = d[p * 2] + d[p * 2 + 1];
    }

    int getsum(int l, int r, int s, int t, int p) {
        // [l,r] 为查询区间,[s,t] 为当前节点包含的区间,p为当前节点的编号
        if (l <= s && t <= r) return d[p];
        // 当前区间为询问区间的子集时直接返回当前区间的和
        int m = (s + t) / 2;
        if (b[p]) {
            // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
            d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m),
            b[p * 2] += b[p], b[p * 2 + 1] += b[p];  // 将标记下传给子节点
            b[p] = 0;                                    // 清空当前节点的标记
        }
        int sum = 0;
        if (l <= m) sum = getsum(l, r, s, m, p * 2);
        if (r > m) sum += getsum(l, r, m + 1, t, p * 2 + 1);
        return sum;
    }
}
#endif //LEETCODE_DATA_STRUCTURE_H
