//
// Created by panrenhua on 1/9/21.
//

#ifndef LEETCODE_LEETCODE_1206_H
#define LEETCODE_LEETCODE_1206_H

#include "allheaders.h"
/** 1206. 设计跳表
 * */

static const int SKIPLIST_P_VAL = RAND_MAX / 2, MAX_LEVEL = 16;
class Skiplist {
public:
    struct Node {
        int val;
        vector<Node *> level;
        Node(int val, int size = MAX_LEVEL) : val(val), level(size) {}
    };

    Node head;
    int maxlevel = 1;
    Skiplist() : head(INT_MIN, MAX_LEVEL) {}

    bool search(int target) {
        Node * prev = _search(target)[0];
        return prev->level[0] && prev->level[0]->val == target;
    }

    vector<Node *> _search(int key) {
        Node * cur = &head;
        vector<Node *> prevs(MAX_LEVEL);
        for (int i = maxlevel - 1; i >= 0; i--) {
            while (cur->level[i] && cur->level[i]->val < key)
                cur = cur->level[i];
            prevs[i] = cur;
        }

        return prevs;
    }

    void add(int num) {
        auto prevs = _search(num);
        int level = random_level();
        if (level > maxlevel) {
            for (int i = maxlevel; i < level; i++)
                prevs[i] = &head;
            maxlevel = level;
        }
        Node * cur = new Node(num, level);
        for (int i = level - 1; i >= 0; i--) {
            cur->level[i] = prevs[i]->level[i];
            prevs[i]->level[i] = cur;
        }
    }

    bool erase(int num) {
        auto prevs = _search(num);
        if (!prevs[0]->level[0] || prevs[0]->level[0]->val != num)
            return false;
        Node * del = prevs[0]->level[0];
        for (int i = 0; i < maxlevel; i++)
            if (prevs[i]->level[i] == del)
                prevs[i]->level[i] = del->level[i];
        delete del;
        while (maxlevel > 1 && !head.level[maxlevel - 1])
            maxlevel--;
        return true;
    }

    static int random_level() {
        int level = 1;
        while (rand() < SKIPLIST_P_VAL && level < MAX_LEVEL) level++;
        return level;
    }
};


#endif //LEETCODE_LEETCODE_1206_H
