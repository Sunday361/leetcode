//
// Created by panrenhua on 3/26/21.
//

#ifndef LEETCODE_LEETCODE_145_H
#define LEETCODE_LEETCODE_145_H
#include "allheaders.h"
/** 145. 二叉树的后序遍历
 *
 * 这一类型的题都是一套模板
 * while(root != nullptr || !stk.empty()) {
 *      while (root != nullptr) {
 *          stk.emplace_back(root);
 *          root = root->left;
 *      }
 *
 *      root = stk.back();
 *      // 后序遍历需要一个指针, 记录之前访问过得节点, 当右节点为空,或者右节点已经访问过了的时候 访问
 *      if (root->right == nullptr || root->right == prev) {
 *          访问 root->val
 *      }
 *      // 中序遍历需要在 pop_back() 的时候 访问
 *
 *      // 前序遍历, 需要在 push_back() 的时候 访问
 * }
 * */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        vector<TreeNode*> stk;
        TreeNode* prev = nullptr;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.emplace_back(root);
                root = root->left;
            }

            root = stk.back();
            // 如果右子树为空, 或者其右子树已经被访问过了
            if (root->right == nullptr || root->right == prev) {
                stk.pop_back();
                ans.emplace_back(root->val);
                prev = root;
                root = nullptr;
            }else {
                root = root->right;
            }
        }

        return ans;
    }
};
#endif //LEETCODE_LEETCODE_145_H
