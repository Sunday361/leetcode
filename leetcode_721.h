//
// Created by panrenhua on 1/7/21.
//

#ifndef LEETCODE_LEETCODE_721_H
#define LEETCODE_LEETCODE_721_H

#include "allheaders.h"
/** 721. 账户合并
 *  并查集 所有email作为一个大的map, 里面存储使用的人的编号
 *  遍历所有邮箱 使所有邮箱编号只指向同一个人(root)
 *
 *  最后 遍历所有人 取出祖先节点 返回其含有的邮箱
 * */
class Solution {
public:
    vector<int> v;
    inline int findRoot(int k) {
        while(k != v[k]) {
            k = v[k];
        }
        return k;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        v.resize(accounts.size());
        vector<vector<string>> ans;
        unordered_map<string, int> emails;
        for (int i = 0; i < v.size(); i++) {
            v[i] = i;
        }

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                /** 这个地方一开始想错了 浪费了太多的时间 一个邮箱只会对应一个名字 */
                if (emails.find(accounts[i][j]) != emails.end()) {
                    v[findRoot(emails[accounts[i][j]])] = i;
                }
                emails[accounts[i][j]] = i;
            }
        }
        map<int, set<string>> res;
        for (int i = 0; i < v.size(); i++) {
            int root = findRoot(i);
            for (int j = 1; j < accounts[i].size(); j++) {
                res[root].insert(accounts[i][j]);
            }
        }

        for (int i = 0; i < v.size(); i++) {
            if (i == v[i]) {
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for (auto& email : res[i]) {
                    temp.push_back(email);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

#endif //LEETCODE_LEETCODE_721_H
