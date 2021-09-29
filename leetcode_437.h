//
// Created by panrenhua on 2021/9/28.
//

#ifndef LEETCODE_LEETCODE_437_H
#define LEETCODE_LEETCODE_437_H

#include "allheaders.h"

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        return pathSum(root, targetSum, v);
    }

    int pathSum(TreeNode* root, int targetSum, vector<int>& paths) {
        if (root) {
            vector<int> l, r;
            int left = pathSum(root->left, targetSum, l);
            int right = pathSum(root->right, targetSum, r);
            int ans = left + right;
            paths = l;
            paths.insert(paths.end(), r.begin(), r.end());
            for (auto& path : paths) {
                if (targetSum == path + root->val) {
                    ++ans;
                }
                path += root->val;
            }
            if (root->val == targetSum) ++ans;
            paths.push_back(root->val);
            return ans;
        }
        return 0;
    }
};

#endif //LEETCODE_LEETCODE_437_H
