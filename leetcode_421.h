//
// Created by panrenhua on 12/27/20.
//

#ifndef LEETCODE_LEETCODE_421_H
#define LEETCODE_LEETCODE_421_H

/** 421. 数组中两个数的最大异或值
 * 使用 trie存储 nums[i] 对应的 二进制数
 * 最大的异或值应该是对应的 尽可能不相同的位
 * */
#include "allheaders.h"
struct node{
    struct node *left;
    struct node *right;
    int val;
    node(int val) : val(val), left(NULL), right(NULL) {}
};
#define BIT (1 << 30)
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        node* trie = new node(0);
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            int bit = BIT;
            int ans = 0;
            node* p = trie;
            node* q = trie;
            for (int j = 0; j < 31; j++) {
                ans = (ans << 1);
                if (nums[i] & (bit >> j)) {
                    if (p->right == NULL) {
                        p->right = new node(1);
                    }
                    p = p->right;
                    if (q->left != NULL) {
                        ans += 1;
                        q = q->left;
                    }else {
                        q = q->right;
                    }
                }else {
                    if (p->left == NULL) {
                        p->left = new node(0);
                    }
                    p = p->left;
                    if (q->right != NULL) {
                        ans += 1;
                        q = q->right;
                    }else {
                        q = q->left;
                    }
                }
            }
            res = max(res, ans);
        }
        return res;
    }
};

#endif //LEETCODE_LEETCODE_421_H
