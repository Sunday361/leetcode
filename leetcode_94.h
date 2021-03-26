//
// Created by panrenhua on 3/26/21.
//

#ifndef LEETCODE_LEETCODE_94_H
#define LEETCODE_LEETCODE_94_H
#include "allheaders.h"
/** 94. 二叉树的中序遍历
 * */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> stk;
        vector<int> ans;
        while (root != nullptr || !stk.empty()) { // 栈不空或者指针不为空
            while (root != nullptr) {
                stk.emplace_back(root);
                root = root->left;
            }

            root = stk.back();
            stk.pop_back();
            ans.push_back(root->val);
            root = root->right;
        }

        return ans;
    }
};
#endif //LEETCODE_LEETCODE_94_H
