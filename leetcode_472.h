//
// Created by panrenhua on 4/7/21.
//

#ifndef LEETCODE_LEETCODE_472_H
#define LEETCODE_LEETCODE_472_H
#include "allheaders.h"
/** 472. 连接词
 * */
class Solution {
public:
    class Trie{
    public:
        struct node {
            bool isLeaf;
            struct node* next[26];
        };
        node* root;
        Trie() {
            root = new node();
        }

        void insert(string& s) {
            node* p = root;
            for (int i = 0; i < s.size(); i++) {
                if (p->next[s[i] - 'a'] == nullptr) {
                    p->next[s[i] - 'a'] = new node();
                }
                p = p->next[s[i] - 'a'];
            }
            p->isLeaf = true;
        }

        bool startWith(string& s) {
            node* p = root;
            for (int i = 0; i < s.size(); i++) {
                if (p->next[s[i] - 'a'] == nullptr) {
                    return false;
                }
                p = p->next[s[i] - 'a'];
            }

            if (p->isLeaf) {
                return true;
            }
            return false;
        }
    };
    Trie* trie;
    bool dfs(string& s, int count, vector<int>& dp, int k) {
        if (dp[k] != -1) return dp[k];
        if (k == s.size() && count > 1) return dp[k] = 1;
        for (int i = k; i < s.size(); i++) {
            string ss = s.substr(k, i - k + 1);
            if (trie->startWith(ss) && dfs(s, count + 1, dp, i + 1)) {
                return dp[k] = 1;
            }
        }
        return dp[k] = 0;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        trie = new Trie();
        for (auto& word : words) {
            trie->insert(word);
        }

        vector<string> ans;
        for (auto& word : words) {
            vector<int> dp(word.size() + 1, -1);
            if (dfs(word, 0, dp, 0)) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};
#endif //LEETCODE_LEETCODE_472_H
