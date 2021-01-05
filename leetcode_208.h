//
// Created by panrenhua on 1/5/21.
//

#ifndef LEETCODE_LEETCODE_208_H
#define LEETCODE_LEETCODE_208_H

/** 208. 实现 Trie (前缀树)
 * */
#include "allheaders.h"
class Trie {
public:
    struct node{
        char val;
        bool isleaf;
        node* next[26] = { nullptr };
        node(char c, bool isleaf): val(c), isleaf(isleaf) {}
    };

    node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new node('a', false);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int i = 0;
        node* p = root;
        while(i < word.size()) {
            if (p->next[word[i] - 'a'] == nullptr) {
                p->next[word[i] - 'a'] = new node(word[i], false);
            }
            p = p->next[word[i] - 'a'];
            i++;
        }
        p->isleaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int i = 0;
        node* p = root;

        while (i < word.size()) {
            if (p->next[word[i] - 'a'] == nullptr) {
                return false;
            }else {
                p = p->next[word[i] - 'a'];
                i++;
            }
        }
        if (p->isleaf) return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int i = 0;
        node* p = root;

        while (i < prefix.size()) {
            if (p->next[prefix[i] - 'a'] == nullptr) {
                return false;
            }else {
                p = p->next[prefix[i] - 'a'];
                i++;
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#endif //LEETCODE_LEETCODE_208_H
