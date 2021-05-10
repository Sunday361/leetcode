//
// Created by panrenhua on 5/10/21.
//

#ifndef LEETCODE_LEETCODE_872_H
#define LEETCODE_LEETCODE_872_H
#include "allheaders.h"
/** 872. 叶子相似的树
 * */
class Solution {
public:
    vector<int> v1, v2;
    void dfs(TreeNode* t, vector<int>& v) {
        if (!t) return;
        if (!t->left && !t->right) {
            v.push_back(t->val);
            return;
        }
        dfs(t->left, v);
        dfs(t->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs(root1, v1);
        dfs(root2, v2);
        if (v1.size() != v2.size()) return false;
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
};
#endif //LEETCODE_LEETCODE_872_H
