//
// Created by panrenhua on 3/13/21.
//

#ifndef LEETCODE_LEETCODE_705_H
#define LEETCODE_LEETCODE_705_H

#include "allheaders.h"
class MyHashSet {
public:
    /** Initialize your data structure here. */
    struct node {
        struct node *next;
        int key;
        node(int k): key(k), next(nullptr){}
    };
    vector<node*> v;
    const int N = 1e5 + 7;
    MyHashSet() {
        v.resize(N, new node(-1));
    }

    void add(int key) {
        int value = key % N;
        node* n = v[value]->next;
        while(n && n->key != key) {
            n = n->next;
        }
        if (!n) {
            node* p = new node(key);
            p->next = v[value]->next;
            v[value]->next = p;
        }
    }

    void remove(int key) {
        int value = key % N;
        node* p = v[value]->next;
        node* f = v[value];
        while (p && p->key != key) {
            p = p->next;
            f = f->next;
        }
        if (p) {
            f->next = p->next;
            delete p;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int value = key % N;
        node* p = v[value]->next;
        while (p && p->key != key) {
            p = p->next;
        }
        if (p) return true;
        return false;
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
#endif //LEETCODE_LEETCODE_705_H
