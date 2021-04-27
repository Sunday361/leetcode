//
// Created by panrenhua on 4/27/21.
//

#ifndef LEETCODE_LEETCODE_938_H
#define LEETCODE_LEETCODE_938_H
#include "allheaders.h"
/** 938. 二叉搜索树的范围和
 * */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root) {
            if (root->val >= low && root->val <= high) {
                return rangeSumBST(root->left, low, root->val)
                + rangeSumBST(root->right, root->val, high) + root->val;
            }else if (root->val < low) {
                return rangeSumBST(root->right, low, high);
            }else {
                return rangeSumBST(root->left, low, high);
            }
        }else {
            return 0;
        }
    }
};
#endif //LEETCODE_LEETCODE_938_H
