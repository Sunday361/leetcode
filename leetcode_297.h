#ifndef CPP_LEETCODE_297_H
#define CPP_LEETCODE_297_H

#include "allheaders.h"
/** 297. 二叉树的序列化与反序列化
 * */
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) {
            return "#";
        }
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }
    TreeNode* deserialize(stringstream& ss) {
        string temp;
        ss >> temp;

        if (temp == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(temp));
        root->left = deserialize(ss);
        root->right = deserialize(ss);
        return root;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);

        return deserialize(ss);
    }
};

#endif //CPP_LEETCODE_297_H
