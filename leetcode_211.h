//
// Created by panrenhua on 1/5/21.
//

#ifndef LEETCODE_LEETCODE_211_H
#define LEETCODE_LEETCODE_211_H

#include "allheaders.h"
/** 211. 添加与搜索单词 - 数据结构设计
 * */
class WordDictionary {
public:
    struct node{
        char val;
        bool isleaf;
        node* next[26] = { nullptr };
        node(char c, bool isleaf): val(c), isleaf(isleaf) {}
    };

    node* root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new node('.', false);
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
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

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int i = 0;
        node* p = root;

        return search(word, i, p);
    }

    bool search(string& word, int k, node* p) {
        if (k == word.size() && p->isleaf) return true;
        else if (k == word.size() && !p->isleaf) return false;
        if (word[k] == '.') {
            for (int i = 0; i < 26; i++) {
                if (p->next[i] != nullptr) {
                    bool res = search(word, k + 1, p->next[i]);
                    if (res) return res;
                }
            }
            return false;
        }
        if (p->next[word[k] - 'a'] == nullptr) return false;
        return search(word, k + 1, p->next[word[k] - 'a']);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
#endif //LEETCODE_LEETCODE_211_H
