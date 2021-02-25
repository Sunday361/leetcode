//
// Created by panrenhua on 2/24/21.
//

#ifndef LEETCODE_LEETCODE_113_H
#define LEETCODE_LEETCODE_113_H

#include "allheaders.h"
/** 113. 路径总和 II
 * */
#include "allheaders.h"
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;
    void dfs(TreeNode* root, int targetSum) {
        if (!root) return;
        if (root->val == targetSum && root->left == root->right) {
            v.push_back(root->val);
            ans.push_back(v);
            v.pop_back();
        }else {
            v.push_back(root->val);
            dfs(root->left, targetSum - root->val);
            dfs(root->right, targetSum - root->val);
            v.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};
#endif //LEETCODE_LEETCODE_113_H
