//
// Created by panrenhua on 2/24/21.
//

#ifndef LEETCODE_OFFER_36_H
#define LEETCODE_OFFER_36_H

#include "allheaders.h"
/** 剑指 Offer 36. 二叉搜索树与双向链表
 * */

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        Node* left = treeToDoublyList(root->left);
        Node* right = treeToDoublyList(root->right);

        if (left && right) {
            Node* lr = left->left;
            Node* rr = right->left;

            root->right = right;
            right->left = root;
            root->left = lr;
            lr->right = root;
            left->left = rr;
            rr->right = left;
            return left;
        }else if (left) {
            Node* lr = left->left;
            lr->right = root;
            root->left = lr;
            root->right = left;
            left->left = root;
            return left;
        }else if (right) {
            Node* rr = right->left;
            root->right = right;
            right->left = root;
            root->left = rr;
            rr->right = root;
            return root;
        }else {
            root->left = root;
            root->right = root;
        }
        return root;
    }
};

#endif //LEETCODE_OFFER_36_H
