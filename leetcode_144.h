//
// Created by panrenhua on 3/26/21.
//

#ifndef LEETCODE_LEETCODE_144_H
#define LEETCODE_LEETCODE_144_H
#include "allheaders.h"
/** 144. 二叉树的前序遍历
 * */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> stk;
        vector<int> ans;

        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                ans.push_back(root->val);
                stk.emplace_back(root);
                root = root->left;
            }

            root = stk.back();
            stk.pop_back();
            root = root->right;
        }

        return ans;
    }
};
#endif //LEETCODE_LEETCODE_144_H
