//
// Created by panrenhua on 3/4/21.
//

#ifndef LEETCODE_LEETCODE_173_H
#define LEETCODE_LEETCODE_173_H

#include "allheaders.h"
/** 173. 二叉搜索树迭代器
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 * 用一个数组存放左子序列
 */
class BSTIterator {
public:
    vector<TreeNode*> v;
    BSTIterator(TreeNode* root) {
        auto left = root;
        while (left) {
            v.push_back(left);
            left = left->left;
        }
    }

    int next() {
        int ans;
        TreeNode* p = v.back();
        ans = p->val;
        v.pop_back();
        p = p->right;
        while (p) {
            v.push_back(p);
            p = p->left;
        }
        return ans;
    }

    bool hasNext() {
        if (!v.empty()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
#endif //LEETCODE_LEETCODE_173_H
