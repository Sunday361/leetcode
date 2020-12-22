//
// Created by panrenhua on 2020/12/22.
//

#ifndef LEETCODE_LEETCODE_103_H
#define LEETCODE_LEETCODE_103_H

#include "allheaders.h"
/** 103. 二叉树的锯齿形层序遍历
 * */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(!q.empty()) {
            vector<int> v;
            int len = q.size();
            while(len > 0) {
                TreeNode* p = q.front();
                q.pop();
                v.push_back(p->val);
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
                len--;
            }
            if (!flag)
                reverse(v.begin(), v.end());
            ans.push_back(v);
            flag = !flag;
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_103_H
