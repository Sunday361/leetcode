//
// Created by panrenhua on 2/24/21.
//

#ifndef LEETCODE_OFFER_26_H
#define LEETCODE_OFFER_26_H
#include "allheaders.h"
/** 剑指 Offer 26. 树的子结构
 * */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B, int f) {
        if (!B) return true;
        else if (!A){
            return false;
        }
        if (f == 1) {
            if (A->val == B->val) {
                return isSubStructure(A->left, B->left, 1) && isSubStructure(A->right, B->right, 1);
            }else {
                return false;
            }
        }else {
            if (A->val == B->val) {
                bool ans = isSubStructure(A->left, B->left, 1) && isSubStructure(A->right, B->right, 1);
                if (ans) return ans;
            }
            return isSubStructure(A->left, B, 0) || isSubStructure(A->right, B, 0);
        }
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B) return false;
        return isSubStructure(A, B, 0);
    }
};
#endif //LEETCODE_OFFER_26_H
