//
// Created by panrenhua on 3/12/21.
//

#ifndef LEETCODE_LEETCODE_449_H
#define LEETCODE_LEETCODE_449_H
/** 449. 序列化和反序列化二叉搜索树
 */
#include "allheaders.h"
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "#";

        return to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    /// 对stringstream 是引用 先调用rebuild 解析了左子树 此时剩下的stringstream 就是右子数
    TreeNode* rebuildTree(stringstream &ss){
        string tmp;
        ss >> tmp;

        if(tmp == "#") /// 这里用 # 隔开遇到 # 返回
            return nullptr;

        TreeNode* node = new TreeNode(stoi(tmp));
        node->left = rebuildTree(ss);
        node->right = rebuildTree(ss);

        return node;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return rebuildTree(ss);
    }
};

#endif //LEETCODE_LEETCODE_449_H
