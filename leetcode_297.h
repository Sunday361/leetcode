#ifndef CPP_LEETCODE_297_H
#define CPP_LEETCODE_297_H

#include "allheaders.h"

class Codec {
public:
    string serialize(TreeNode* root) {
        string res = "";
        vector<TreeNode*> q;
        if (!root) return res;
        q.push_back(root);
        while(!q.empty()) {
            vector<TreeNode* > temp;
            int flag = 0;
            for (int i = 0; i < q.size(); i++) {
                res.append((q[i] == NULL ? " " : to_string(q[i]->val)) + ",");
                if (q[i]) {
                    temp.push_back(q[i]->left);
                    temp.push_back(q[i]->right);
                    if (q[i]->left || q[i]->right) flag = 1;
                }
            }
            if (flag) q = temp;
            else q.clear();
        }
        return res;
    }

    TreeNode* deserialize(string data) {
        vector<TreeNode*> up;
        vector<string> tree;
        istringstream is = istringstream(data);
        char flag = ',';
        string temp;
        while(getline(is, temp, flag)) {
            tree.push_back(temp);
        }
        if (tree.size() == 0) return NULL;
        TreeNode* head = new TreeNode(stoi(tree[0]));
        up.push_back(head);
        int index = 1;
        while(index < tree.size()) {
            vector<TreeNode*> down;
            for (int i = 0; i < up.size(); i++) {
                up[i]->left = (tree[index] == " ") ? NULL : new TreeNode(stoi(tree[index]));
                if (up[i]->left) down.push_back(up[i]->left);
                index++;
                up[i]->right = (tree[index] == " ") ? NULL : new TreeNode(stoi(tree[index]));
                if (up[i]->right) down.push_back(up[i]->right);
                index++;
            }
            up = down;
        }
        return head;
    }
};

#endif //CPP_LEETCODE_297_H
